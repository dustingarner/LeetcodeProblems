class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 < n2){return findMedianSortedArrays(nums2, nums1);}
        if(n2 == 0){
            return n1 % 2 ? (double)nums1[n1/2] : (nums1[n1/2] + nums1[(n1/2)-1]) / 2.0;
        }
        int partition = (n1 + n2) / 2;
        int l = 0, r = n2;
        while(l <= r){
            int mid2 = (l+r)/2;
            int mid1 = partition - mid2;
            int l1 = INT_MIN, r1 = INT_MAX, l2 = INT_MIN, r2 = INT_MAX;

            if(mid2 < n2){
                r2 = nums2[mid2];
            }
            if(mid2 > 0){
                l2 = nums2[mid2-1];
            }
            if(mid1 < n1){
                r1 = nums1[mid1];
            }
            if(mid1 > 0){
                l1 = nums1[mid1-1];
            }

            if(l1 <= r2 && l2 <= r1){
                if((n1+n2) % 2){
                    return (double)min(r1, r2);
                }
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            if(l1 > r2){
                l = mid2 + 1;
            }
            else{
                r = mid2 - 1;
            }
        }
        return -1;
    }
};
