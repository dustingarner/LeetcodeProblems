class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo (coins.size(), vector<int> (amount+1, -1));
        return getAmounts(amount, 0, coins, memo);
    }

    int getAmounts(int amount, int index, vector<int>& coins, vector<vector<int>>& memo){
        if(amount<0){
            return 0;
        }
        if(memo[index][amount]!=-1){
            return memo[index][amount];
        }
        if(amount==0){
            memo[index][amount] = 1;
            return memo[index][amount];
        }
        if(index==coins.size()-1){
            memo[index][amount] = amount%coins[index]==0 ? 1 : 0;
            return memo[index][amount];
        }
        int changeCount = 0;
        changeCount += getAmounts(amount, index+1, coins, memo);
        changeCount += getAmounts(amount-coins[index], index, coins, memo);
        memo[index][amount] = changeCount;
        return memo[index][amount];
    }
};
