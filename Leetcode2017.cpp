class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long swPoints = 0;
        long long  nePoints = 0;
        for(int i = 1; i < grid[0].size(); ++i){
            nePoints += grid[0][i];
        }
        long long minPoints = nePoints;
        for(int i = 1; i < grid[0].size(); ++i){
            nePoints -= grid[0][i];
            swPoints += grid[1][i-1];
            minPoints = min(minPoints, max(nePoints, swPoints));
        }
        return minPoints;
    }
};
