class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distReachable = 0;
        for(int i=nums.size()-2; i>=0; --i){
            distReachable++;
            if(nums[i]>=distReachable){
                distReachable = 0;
            }
        }
        return distReachable==0;
    }
};
