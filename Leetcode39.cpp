class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int index=0) {
        if(index == 0){sort(candidates.begin(), candidates.end());}
        vector<vector<int>> combinations;
        if(target == 0){return combinations;}
        if(index >= candidates.size()){return combinations;}
        if(candidates[index] > target){return combinations;}
        int multiplier = 0;
        while(multiplier * candidates[index] <= target){
            int currentSum = multiplier * candidates[index];
            vector<int> chain (multiplier, candidates[index]);
            if(currentSum == target){
                combinations.push_back(chain);
            }
            vector<vector<int>> nextSums = combinationSum(candidates, target-currentSum, index+1);
            for(int i = 0; i < nextSums.size(); ++i){
                vector<int> tempCombo = chain;
                tempCombo.insert(tempCombo.end(), nextSums[i].begin(), nextSums[i].end());
                combinations.push_back(tempCombo);
            }
            multiplier++;
        }
        return combinations;
    }
};
