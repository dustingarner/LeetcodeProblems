class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int maxElapsed = 0;
        bool hasFresh = false;
        vector<vector<int>> seenCoords (grid.size(), vector<int> (grid[0].size(), INT_MAX));
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]!=1){
                    continue;
                }
                hasFresh = true;
                int minLength = INT_MAX;
                findPath(grid, make_pair(i, j), minLength, seenCoords);
                if(minLength == INT_MAX){
                    return -1;
                }
                seenCoords[i][j] = minLength;
                maxElapsed = max(maxElapsed, minLength);
            }
        }
        if(!hasFresh){
            return 0;
        }
        for(auto x:seenCoords){
            for(auto y:x){
                cout <<y <<" ";
            }cout<<endl;
        }
        return maxElapsed;
    }

    void findPath(vector<vector<int>>& grid, pair<int, int> coord, int& minLength,
            vector<vector<int>>& seenCoords){
        int i = coord.first, j = coord.second;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return;
        }
        if(grid[i][j]==0){
            return;
        }
        if(grid[i][j]==2){
            minLength = 0;
            return;
        }
        if(seenCoords[i][j]==-1){
            return;
        }
        if(seenCoords[i][j]!=INT_MAX){
            minLength = seenCoords[i][j];
            return;
        }
        seenCoords[i][j] = -1;
        vector<int> directions = {0, 1, 0, -1, 0};
        for(int k=1; k<directions.size(); ++k){
            int tempI = i+directions[k], tempJ = j+directions[k-1];
            if(tempI<0 || tempJ<0 || tempI>=grid.size() || tempJ>=grid[0].size()){
                continue;
            }
            int tempMin = INT_MAX;
            findPath(grid, make_pair(i+directions[k], j+directions[k-1]), tempMin, seenCoords);
            if(tempMin==INT_MAX){
                continue;
            }
            minLength = min(tempMin+1, minLength);
        }
        seenCoords[i][j] = INT_MAX;
    }
};
