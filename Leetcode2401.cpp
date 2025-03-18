class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int longest = 1, currentLength = 1;
        int currentSum = nums[0];
        while(r < nums.size()){
            if(l == r){
                currentLength = 1;
                currentSum = nums[l];
                r++;
                continue;
            }
            if((currentSum & nums[r]) == 0){
                currentSum += nums[r];
                currentLength++;
                longest = max(longest, currentLength);
                r++;
            }
            else{
                currentSum -= nums[l];
                currentLength--;
                l++;
            }
        }
        return longest;
    }
};
