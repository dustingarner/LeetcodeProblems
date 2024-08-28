class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslandCount = 0;
        for(int i=0; i<grid1.size(); ++i){
            for(int j=0; j<grid1[0].size(); ++j){
                if(grid2[i][j]==1){
                    bool isSubisland = true;
                    findSubisland(grid1, grid2, {i, j}, isSubisland);
                    if(isSubisland){
                        subIslandCount++;
                    }
                }
            }
        }
        return subIslandCount;

    }

    void findSubisland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, pair<int, int> coord,
            bool& isSubisland){
        int n = coord.first, m = coord.second;
        if(n<0 || m<0 || n>=grid1.size() || m>=grid1[0].size()){
            return;
        }
        if(grid2[n][m]==0){
            return;
        }
        if(grid1[n][m]==0){
            isSubisland = false;
        }
        grid2[n][m] = 0;
        vector<int> directions = {0, -1, 0, 1, 0};
        for(int i=1; i<directions.size(); ++i){
            int nextN = n+directions[i], nextM = m+directions[i-1];
            findSubisland(grid1, grid2, {n+directions[i], m+directions[i-1]}, isSubisland);
        }
    }
};
