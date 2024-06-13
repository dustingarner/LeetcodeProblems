class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> seenNums (nums.size(), -1);
        return maxValue(nums, 0, seenNums);
    }

    int maxValue(vector<int>& nums, int index, vector<int>& seenNums){
        if(index >= nums.size()){
            return 0;
        }
        if(seenNums[index] != -1){
            return seenNums[index];
        }
        int useValue = nums[index] + maxValue(nums, index+2, seenNums);
        int skipValue = maxValue(nums, index+1, seenNums);
        int higherValue = max(useValue, skipValue);
        seenNums[index] = higherValue;
        return higherValue;
    }
};
