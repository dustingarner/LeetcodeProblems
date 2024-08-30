class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo (2, vector<int> (prices.size(), 0));
        for(int i=prices.size()-1; i>=0; --i){
            if(i==prices.size()-1){
                memo[0][i] = 0;
                memo[1][i] = prices[i];
                continue;
            }
            memo[0][i] = max(-prices[i]+memo[1][i+1], memo[0][i+1]);
            int afterCooldown = i==prices.size()-2 ? 0 : memo[0][i+2];
            memo[1][i] = max(prices[i]+afterCooldown, memo[1][i+1]);
        }
        return memo[0][0];
    }
};
