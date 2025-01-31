class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> seenCells (grid.size(), vector<bool> (grid[0].size(), false));
        vector<vector<pair<int, int>>> islands (grid.size(), 
                vector<pair<int, int>> (grid[0].size(), {0, 0}));
        int islandIndex = 1;
        int maxFill = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] != 1){
                    continue;
                }
                if(islands[i][j].first != 0){
                    continue;
                }
                int islandSize = getIslandSize({i, j}, grid, seenCells);
                maxFill = max(islandSize, maxFill);
                fillIsland({islandSize, islandIndex}, {i, j}, grid, islands);
                islandIndex++;
            }
        }
        vector<int> directions = {0, -1, 0, 1, 0};
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] != 0){
                    continue;
                }
                vector<pair<int, int>> adjacentIslands (4, {0, 0});
                int tempFill = 1;
                for(int k = 1; k < directions.size(); ++k){
                    int newI = i + directions[k], newJ = j + directions[k-1];
                    if(newI < 0 || newJ < 0 || newI >= grid.size() || newJ >= grid[0].size()){
                        continue;
                    }
                    if(grid[newI][newJ] == 0){
                        continue;
                    }
                    pair<int, int> tempIsland = islands[newI][newJ];
                    adjacentIslands[k-1] = tempIsland;
                    for(int l = 0; l < k-1; ++l){
                        if(adjacentIslands[l].second == tempIsland.second){
                            adjacentIslands[k-1] = {0, 0};
                            break;
                        }
                    }
                    tempFill += adjacentIslands[k-1].first;
                }
                maxFill = max(tempFill, maxFill);
            }
        }
        return maxFill;
    }

    int getIslandSize(pair<int, int> index, vector<vector<int>>& grid, vector<vector<bool>>& seenCells){
        int n = index.first, m = index.second;
        seenCells[n][m] = true;
        vector<int> directions = {0, -1, 0, 1, 0};
        int islandSize = 1;
        for(int i = 1; i < directions.size(); ++i){
            int newN = n + directions[i], newM = m + directions[i-1];
            if(newN < 0 || newM < 0 || newN >= grid.size() || newM >= grid[0].size()){
                continue;
            }
            if(grid[newN][newM] == 0 || seenCells[newN][newM]){
                continue;
            }
            islandSize += getIslandSize({newN, newM}, grid, seenCells);
        }
        return islandSize;
    }

    void fillIsland(pair<int, int> islandInfo, pair<int, int> index, 
            vector<vector<int>>& grid, vector<vector<pair<int, int>>>& islands){
        int n = index.first, m = index.second;
        islands[n][m] = islandInfo;
        vector<int> directions = {0, -1, 0, 1, 0};
        for(int i = 1; i < directions.size(); ++i){
            int newN = n + directions[i], newM = m + directions[i-1];
            if(newN < 0 || newM < 0 || newN >= grid.size() || newM >= grid[0].size()){
                continue;
            }
            if(grid[newN][newM] == 0 || islands[newN][newM].second == islandInfo.second){
                continue;
            }
            fillIsland(islandInfo, {newN, newM}, grid, islands);
        }
    }
};
