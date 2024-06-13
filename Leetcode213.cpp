class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> seenValues (nums.size(), -1);
        int firstHouse = getMaxValue(nums, 0, seenValues, true);
        for(int i = 0; i<seenValues.size(); ++i){
            seenValues[i] = -1;
        }
        int secondHouse = getMaxValue(nums, 1, seenValues, false);
        return max(firstHouse, secondHouse);
    }

    int getMaxValue(vector<int>& nums, int index, vector<int>& seenValues, bool firstSeen){
        if(index >= nums.size()){
            return 0;
        }
        if(nums.size() == 1){
            return nums[index];
        }
        if(index == nums.size()-1 && firstSeen){
            return 0;
        }
        if(seenValues[index] != -1){
            return seenValues[index];
        }
        int usedValue = nums[index] + getMaxValue(nums, index+2, seenValues, firstSeen);
        int skipValue = getMaxValue(nums, index+1, seenValues, firstSeen);
        int maxValue = max(usedValue, skipValue);
        seenValues[index] = maxValue;
        return maxValue;
    }
};
