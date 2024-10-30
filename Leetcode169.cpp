class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int candidate = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            count += nums[i] == candidate ? 1 : -1;
            if(count == 0){
                candidate = nums[i];
                count++;
            }
        }
        return candidate;
    }
};
