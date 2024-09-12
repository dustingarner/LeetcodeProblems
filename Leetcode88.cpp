class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind1 = m-1, ind2 = n-1;
        for(int i=nums1.size()-1; i>=0; --i){
            if(ind2<0){
                nums1[i] = nums1[ind1];
                ind1--;
                continue;
            }
            if(ind1<0){
                nums1[i] = nums2[ind2];
                ind2--;
                continue;
            }
            if(nums2[ind2]>nums1[ind1]){
                nums1[i] = nums2[ind2];
                ind2--;
                continue;
            }
            nums1[i] = nums1[ind1];
            ind1--;
        }
    }
};
