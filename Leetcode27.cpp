class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lastVal = 0;
        int elements = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != val){
                elements++;
            }
            while(lastVal < i && nums[lastVal] != val){
                lastVal++;
            }
            if(lastVal == i || nums[i] == val){
                continue;
            }
            nums[lastVal] = nums[i];
            nums[i] = val;
        }
        return elements;
    }
};
