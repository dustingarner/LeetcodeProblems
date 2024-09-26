class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> memo (nums.size(), vector<int> (nums.size(), -1));
        int maxVal = dp(0, nums.size()-1, 1, 1, nums, memo);
        return maxVal;
    }

    int dp(int start, int end, int leftBookend, int rightBookend, const vector<int>& nums, 
            vector<vector<int>>& memo){
        if(memo[start][end]!=-1){
            return memo[start][end];
        }
        if(start==end){
            memo[start][end] = leftBookend * nums[start] * rightBookend;
            return memo[start][end];
        }
        int maxValue = 0;
        for(int i=start; i<=end; ++i){
            int tempValue = leftBookend * nums[i] * rightBookend;
            if(i!=start){
                tempValue += dp(start, i-1, leftBookend, nums[i], nums, memo);
            }
            if(i!=end){
                int tempLeft = i-1<0 ? 1 : nums[i-1];
                tempValue += dp(i+1, end, nums[i], rightBookend, nums, memo);
            }
            maxValue = max(maxValue, tempValue);
        }
        memo[start][end] = maxValue;
        return maxValue;
    }
};
