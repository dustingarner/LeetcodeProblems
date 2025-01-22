class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> contours (isWater.size(), vector<int> (isWater[0].size(), -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < isWater.size(); ++i){
            for(int j = 0; j < isWater[i].size(); ++j){
                if(isWater[i][j]){
                    q.push({i, j});
                    contours[i][j] = 0;
                }
            }
        }
        vector<int> directions = {0, -1, 0, 1, 0};
        while(!q.empty()){
            pair<int, int> coord = q.front();
            q.pop();
            int y = coord.first, x = coord.second;
            for(int i = 1; i < directions.size(); ++i){
                int newY = y + directions[i], newX = x + directions[i-1];
                if(newY < 0 || newX < 0 || newY >= isWater.size() || newX >= isWater[0].size()){
                    continue;
                }
                if(contours[newY][newX] != -1){
                    continue;
                }
                contours[newY][newX] = contours[y][x] + 1;
                q.push({newY, newX});
            }
        }
        return contours;
    }
};
