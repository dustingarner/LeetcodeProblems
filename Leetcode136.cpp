class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int endXor = 0;
        for(auto x : nums){
            endXor ^= x;
        }
        return endXor;
    }
};
