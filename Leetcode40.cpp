class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> sums;
        vector<int> currentSet;
        addSums(candidates, sums, currentSet, target, 0);
        return sums;
    }

    void addSums(vector<int>& candidates, vector<vector<int>>& sums, vector<int>& currentSet, int target, 
            int index){
        if(target < 0){return;}
        if(target == 0){
            sums.push_back(currentSet);
            return;
        }
        for(int i = index; i < candidates.size(); ++i){
            if(i != index && candidates[i] == candidates[i-1]){continue;}
            currentSet.push_back(candidates[i]);
            addSums(candidates, sums, currentSet, target-candidates[i], i+1);
            currentSet.pop_back();
        }
        return;
    }
};
