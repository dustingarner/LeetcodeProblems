class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int mostNegWindow = 0;
        int maxSum = nums[0];
        for(int i=1; i<nums.size(); ++i){
            mostNegWindow = min(mostNegWindow, currentSum);
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum-mostNegWindow);
        }
        return maxSum;
    }
};
