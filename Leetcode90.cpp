class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> currentSub;
        addSubsets(nums, currentSub, subsets, 0);
        return subsets;
    }

    void addSubsets(vector<int>& nums, vector<int>& currentSub, vector<vector<int>>& subsets, int index){
        subsets.push_back(currentSub);
        for(int i = index; i < nums.size(); ++i){
            if(i != index && nums[i] == nums[i-1]){
                continue;
            }
            currentSub.push_back(nums[i]);
            addSubsets(nums, currentSub, subsets, i+1);
            currentSub.pop_back();
        }
        return;
    }
};
