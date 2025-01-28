class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<bool>> seenCells (grid.size(), vector<bool> (grid[0].size(), false));
        int maxFish = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(seenCells[i][j] || grid[i][j] == 0){
                    continue;
                }
                maxFish = max(maxFish, bfs({i, j}, grid, seenCells));
            }
        }
        return maxFish;
    }

    int bfs(pair<int, int> coord, vector<vector<int>>& grid, vector<vector<bool>>& seenCells){
        queue<pair<int, int>> q;
        q.push(coord);
        vector<int> directions = {0, -1, 0, 1, 0};
        int fish = 0;
        while(!q.empty()){
            int y = q.front().first, x = q.front().second;
            q.pop();
            if(seenCells[y][x]){
                continue;
            }
            seenCells[y][x] = true;
            fish += grid[y][x];
            for(int i = 1; i < directions.size(); ++i){
                int newY = y + directions[i], newX = x + directions[i-1];
                if(newY < 0 || newX < 0 || newY >= grid.size() || newX >= grid[0].size()){
                    continue;
                }
                if(grid[newY][newX] == 0 || seenCells[newY][newX]){
                    continue;
                }
                q.push({newY, newX});
            }
        }
        return fish;
    }
};
