class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> memo (grid.size(), vector<int> (grid[0].size(), -1));
        for(int i = 0; i < grid.size(); ++i){
            memo[i][memo[0].size()-1] = 0;
        }
        int maxMoves = 0;
        for(int i = 0; i < grid.size(); ++i){
            maxMoves = max(maxMoves, getNumMoves(grid, memo, {i, 0}));
        }
        return maxMoves;
    }

    int getNumMoves(vector<vector<int>>& grid, vector<vector<int>>& memo, pair<int, int> index){
        int n = index.first, m = index.second;
        if(memo[n][m] != -1){
            return memo[n][m];
        }
        int maxMoves = 0;
        for(int i = -1; i < 2; ++i){
            int nextN = n + i, nextM = m + 1;
            if(nextN < 0 || nextN >= grid.size()){
                continue;
            }
            if(grid[nextN][nextM] <= grid[n][m]){
                continue;
            }
            maxMoves = max(maxMoves, getNumMoves(grid, memo, {nextN, nextM})+1);
        }
        memo[n][m] = maxMoves;
        return maxMoves;
    }
};
