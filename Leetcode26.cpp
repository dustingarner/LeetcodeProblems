class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fillSpot = -1;
        int numUnique = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i-1]){
                if(fillSpot == -1){
                    fillSpot = i;
                }
                continue;
            }
            numUnique++;
            if(fillSpot == -1){
                continue;
            }
            nums[fillSpot] = nums[i];
            fillSpot++;
        }
        return numUnique;
    }
};
