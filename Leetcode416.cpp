class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto x:nums){
            totalSum += x;
        }
        if(totalSum%2){
            return false;
        }
        int goalSum = totalSum/2;
        vector<vector<bool>> dp (goalSum+1, vector<bool> (nums.size()+1, false));
        for(int i=0; i<=nums.size(); ++i){
            dp[0][i] = true;
        }
        for(int i=1; i<=goalSum; ++i){
            for(int j=1; j<=nums.size(); ++j){
                if(nums[j-1]>i){
                    dp[i][j] = dp[i][j-1];
                }
                else{
                    dp[i][j] = dp[i-nums[j-1]][j-1] || dp[i][j-1];
                }
            }
        }
        return dp[goalSum][nums.size()];
    }
};
