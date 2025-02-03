class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, maxInc = 1, maxDec = 1;
        for(int i = 1; i < nums.size(); ++i){
            maxDec = max(dec, maxDec);
            maxInc = max(inc, maxInc);
            if(nums[i] > nums[i-1]){
                dec = 1;
                inc++;
            }
            else if(nums[i] < nums[i-1]){
                inc = 1;
                dec++;
            }
            else{
                inc = 1;
                dec = 1;
            }
        }
        maxDec = max(dec, maxDec);
        maxInc = max(inc, maxInc);
        return max(maxDec, maxInc);
    }
};
