class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0, equal = 0, more = 0;
        for(auto x:nums){
            if(x == pivot){
                equal++;
            }
            else if(x < pivot){
                less++;
            }
            else{
                more++;
            }
        }
        int lessInd = 0, equalInd = less, moreInd = less + equal;
        vector<int> pivotedNums (nums.size(), 0);
        for(auto x:nums){
            if(x == pivot){
                pivotedNums[equalInd] = x;
                equalInd++;
            }
            else if(x < pivot){
                pivotedNums[lessInd] = x;
                lessInd++;
            }
            else{
                pivotedNums[moreInd] = x;
                moreInd++;
            }
        }
        return pivotedNums;
    }
};
