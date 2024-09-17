class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> leastTimes (n, vector<int> (n, INT_MAX));
        update(grid, leastTimes, {n-1, n-1}, grid[n-1][n-1]);
        return leastTimes[0][0];
    }

    void update(vector<vector<int>>& grid, vector<vector<int>>& leastTimes, pair<int, int> coord, int newTime){
        int n = coord.first, m = coord.second;
        if(n<0 || m<0 || n>=grid.size() || m>=grid[0].size()){
            return;
        }
        if(leastTimes[n][m]<=newTime){
            return;
        }
        leastTimes[n][m] = max(newTime, grid[n][m]);
        vector<int> directions = {0, -1, 0, 1, 0};
        for(int i=1; i<directions.size(); ++i){
            int nextN = n+directions[i], nextM = m+directions[i-1];
            update(grid, leastTimes, {nextN, nextM}, leastTimes[n][m]);
        }
    }
};
