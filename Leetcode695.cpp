class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        vector<vector<bool>> seenSpots (grid.size(), vector<bool> (grid[0].size(), false));
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                int tempArea = getArea(make_pair(i, j), grid, seenSpots);
                maxArea = max(tempArea, maxArea);
            }
        }
        return maxArea;
    }

    int getArea(pair<int, int> coord, vector<vector<int>>& grid, vector<vector<bool>>& seenSpots){
        int y = coord.first, x = coord.second;
        if(grid[y][x] == 0){return 0;}
        if(seenSpots[y][x]){return 0;}
        seenSpots[y][x] = true;
        int area = 1;
        if(y > 0){
            area += getArea(make_pair(y-1, x), grid, seenSpots);
        }
        if(y < grid.size()-1){
            area += getArea(make_pair(y+1, x), grid, seenSpots);
        }
        if(x > 0){
            area += getArea(make_pair(y, x-1), grid, seenSpots);
        }
        if(x < grid[0].size()-1){
            area += getArea(make_pair(y, x+1), grid, seenSpots);
        }
        return area;
    }
};
