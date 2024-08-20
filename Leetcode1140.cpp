class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp (piles.size(), vector<int> (piles.size(), -1));
        vector<int> suffixCount (piles.size(), piles[piles.size()-1]);
        for(int i=piles.size()-2; i>=0; --i){
            suffixCount[i] = piles[i] + suffixCount[i+1];
        }
        return getCount(dp, suffixCount, 0, 1);
    }

    int getCount(vector<vector<int>>& dp, vector<int>& suffixCount, int index, int m){
        if(index+m*2>=suffixCount.size()){
            return suffixCount[index];
        }
        if(dp[index][m]!=-1){
            return dp[index][m];
        }
        int opponentTurn = INT_MAX;
        for(int i=1; i<=m*2; ++i){
            opponentTurn = min(opponentTurn, getCount(dp, suffixCount, index+i, max(m, i)));
        }
        int turn = suffixCount[index]-opponentTurn;
        dp[index][m] = turn;
        return turn;
    }
};
