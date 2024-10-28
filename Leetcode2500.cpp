class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(auto& x:grid){
            sort(x.begin(), x.end());
        }
        int sumValues = 0;
        for(int i = grid[0].size()-1; i >= 0; --i){
            int columnMax = INT_MIN;
            for(int j = 0; j < grid.size(); ++j){
                columnMax = max(columnMax, grid[j][i]);
            }
            sumValues += columnMax;
        }
        return sumValues;
    }
};
