class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<bool> decrements (nums.size(), false);
        int totalFlips = 0;
        int numCurrentFlips = 0;
        for(int i=0; i<nums.size(); ++i){
            bool needsFlip = (nums[i] + numCurrentFlips) % 2 == 0;
            if(needsFlip && i >= nums.size()-k+1){
                return -1;
            }
            else if(needsFlip){
                decrements[i+k-1] = true;
                numCurrentFlips++;
                totalFlips++;
            }
            if(decrements[i]){
                numCurrentFlips--;
            }
        }
        return totalFlips;
    }
};
