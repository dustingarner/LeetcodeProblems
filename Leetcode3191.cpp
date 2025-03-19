class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOps = 0;
        for(int i = 0; i < nums.size()-2; ++i){
            if(nums[i] == 1){
                continue;
            }
            minOps++;
            for(int j = 1; j < 3; j++){
                nums[i+j] = 1 - nums[i+j];
            }
        }
        if(nums[nums.size()-1] == 0 || nums[nums.size()-2] == 0){
            return -1;
        }
        return minOps;
    }
};
