class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ascend = nums[0];
        int maxAscend = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i-1]){
                ascend += nums[i];
                maxAscend = max(ascend, maxAscend);
            }
            else{
                ascend = nums[i];
            }
        }
        return maxAscend;
    }
};
