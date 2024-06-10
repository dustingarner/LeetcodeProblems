class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int endXor = 0;
        for(int i = 0; i <= nums.size(); ++i){
            endXor ^= i;
            if(i == nums.size()){break;}
            endXor ^= nums[i];
        }
        return endXor;
    }
};
