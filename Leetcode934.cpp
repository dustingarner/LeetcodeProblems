class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        bool foundIsland = false;
        queue<pair<int, pair<int, int>>> coast;
        pair<int, int> start;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid.size(); ++j){
                if(grid[i][j]==1){
                    start = make_pair(i, j);
                    foundIsland = true;
                    break;
                }
            }
            if(foundIsland){break;}
        }
        vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
        convertIsland(grid, start, coast, visited);
        for(int i=0; i<visited.size(); ++i){
            for(int j=0; j<visited[0].size(); ++j){
                visited[i][j] = grid[i][j]==2 ? true : false;
            }
        }
        int minBridge = INT_MAX;
        findBridge(grid, coast, minBridge, visited);
        return minBridge;
    }

    void convertIsland(vector<vector<int>>& grid, pair<int, int> coord, queue<pair<int, pair<int, int>>>& coast,
            vector<vector<bool>>& visited){
        int n = coord.first, m = coord.second;
        if(visited[n][m]){
            return;
        }
        visited[n][m] = true;
        if(grid[n][m]==0){
            return;
        }
        grid[n][m] = 2;
        vector<int> directions = {0, -1, 0, 1, 0};
        bool isCoast = false;
        for(int i=1; i<directions.size(); ++i){
            int nextN = n+directions[i], nextM = m+directions[i-1];
            if(nextN<0 || nextM<0 || nextN>=grid.size() || nextM>=grid[0].size()){
                continue;
            }
            if(grid[nextN][nextM]==0){
                isCoast = true;
                continue;
            }
            convertIsland(grid, make_pair(nextN, nextM), coast, visited);
        }
        if(isCoast){
            coast.push(make_pair(0, coord));
        }
    }

    void findBridge(vector<vector<int>>& grid, queue<pair<int, pair<int, int>>>& coast, int& minBridge,
            vector<vector<bool>>& visited){
        vector<int> directions = {0, -1, 0, 1, 0};
        while(!coast.empty()){
            int n = coast.front().second.first, m = coast.front().second.second;
            int val = coast.front().first;
            if(grid[n][m]==1){
                minBridge = val-1;
                break;
            }
            for(int i=1; i<directions.size(); ++i){
                int nextN = n+directions[i], nextM = m+directions[i-1];
                if(nextN<0 || nextM<0 || nextN>=grid.size() || nextM>=grid[0].size()){
                    continue;
                }
                if(visited[nextN][nextM]){
                    continue;
                }
                visited[nextN][nextM] = true;
                if(grid[nextN][nextM]==2){
                    continue;
                }
                coast.push(make_pair(val+1, make_pair(nextN, nextM)));
            }
            coast.pop();
        }
    }
};
