class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int cummulative = 0;
        if(nums1.size() % 2 == 1){
            for(auto& x: nums2){
                cummulative ^= x;
            }
        }
        if(nums2.size() % 2 == 1){
            for(auto& x: nums1){
                cummulative ^= x;
            }
        }
        return cummulative;
    }
};
