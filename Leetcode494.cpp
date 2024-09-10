class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> memo (nums.size());
        for(auto x:{-1, 1}){
            int temp = nums[nums.size()-1] * x;
            if(memo[nums.size()-1].find(temp)==memo[nums.size()-1].end()){
                memo[nums.size()-1][temp] = 0;
            }
            memo[nums.size()-1][temp]++;
        }
        findTargets(nums, target, memo, 0);
        return memo[0][target];
    }

    void findTargets(vector<int>& nums, int target, vector<unordered_map<int, int>>& memo, int index){
        if(memo[index].find(target)!=memo[index].end()){
            return;
        }
        if(index==nums.size()-1){
            memo[index][target] = abs(target)==nums[index] ? 1 : 0;
            return;
        }
        int ways = 0;
        for(auto x:{-1, 1}){
            int temp = nums[index] * x;
            int nextTarget = target - temp;
            findTargets(nums, nextTarget, memo, index+1);
            ways += memo[index+1][nextTarget];
        }
        memo[index][target] = ways;
    }
};
