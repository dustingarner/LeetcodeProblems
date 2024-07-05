class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> permutations;
        for(int i = 0; i < nums.size(); ++i){
            addNumber(permutations, nums[i]);
        }
        return permutations;
    }

    void addNumber(vector<vector<int>>& permutations, int number){
        if(permutations.size() == 0){
            permutations.push_back(vector<int> {number});
            return;
        }
        int currentSize = permutations.size();
        for(int i = 0; i < currentSize; ++i){
            for(int j = 0; j < permutations[i].size(); ++j){
                vector<int> tempPerm = permutations[i];
                tempPerm.insert(tempPerm.begin()+j, number);
                permutations.push_back(tempPerm);
            }
            permutations[i].insert(permutations[i].end(), number);
        }
    }
};
