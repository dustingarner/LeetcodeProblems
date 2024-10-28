class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> lengthStreak;
        int maxStreak = 1;
        for(int i = nums.size()-1; i >= 0; --i){
            if(lengthStreak.find(nums[i]) != lengthStreak.end()){
                continue;
            }
            if(nums[i] >= sqrt(INT_MAX)){
                lengthStreak[nums[i]] = 1;
                continue;
            }
            int square = nums[i] * nums[i];
            if(lengthStreak.find(square) != lengthStreak.end()){
                lengthStreak[nums[i]] = lengthStreak[square] + 1;
                maxStreak = max(maxStreak, lengthStreak[nums[i]]);
                continue;
            }
            lengthStreak[nums[i]] = 1;
        }
        return maxStreak == 1 ? -1 : maxStreak;
    }
};
