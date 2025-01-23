class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int, pair<int, int>> seenColumns;
        unordered_map<int, pair<int, int>> seenRows;
        vector<vector<bool>> counted (grid.size(), vector<bool> (grid[0].size(), false));
        int serverCount = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 0){
                    continue;
                }
                bool addServer = false;
                if(seenRows.find(i) != seenRows.end()){
                    addServer = true;
                    serverCount += !counted[seenRows[i].first][seenRows[i].second];
                    counted[seenRows[i].first][seenRows[i].second] = true;
                }
                else{
                    seenRows[i] = {i, j};
                }
                if(seenColumns.find(j) != seenColumns.end()){
                    addServer = true;
                    serverCount += !counted[seenColumns[j].first][seenColumns[j].second];
                    counted[seenColumns[j].first][seenColumns[j].second] = true;
                }
                else{
                    seenColumns[j] = {i, j};
                }
                serverCount += addServer;
                counted[i][j] = addServer;
            }
        }
        return serverCount;
    }
};
