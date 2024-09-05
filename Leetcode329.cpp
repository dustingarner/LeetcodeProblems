class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> pathLengths (matrix.size(), vector<int> (matrix[0].size(), -1));
        int maxLength = 0;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                int path = getPathLengths(matrix, pathLengths, {i, j});
                maxLength = max(maxLength, path);
            }
        }
        return maxLength;
    }

    int getPathLengths(vector<vector<int>>& matrix, vector<vector<int>>& pathLengths, pair<int, int> coord){
        int n = coord.first, m = coord.second;
        if(pathLengths[n][m]!=-1){
            return pathLengths[n][m];
        }
        int maxPath = 1;
        vector<int> directions = {0, -1, 0, 1, 0};
        for(int i=1; i<directions.size(); ++i){
            int nextN = n+directions[i], nextM = m+directions[i-1];
            if(nextN<0 || nextM<0 || nextN>=matrix.size() || nextM>=matrix[0].size()){
                continue;
            }
            if(matrix[nextN][nextM]<=matrix[n][m]){
                continue;
            }
            int nextPath = 1 + getPathLengths(matrix, pathLengths, {nextN, nextM});
            maxPath = max(maxPath, nextPath);
        }
        pathLengths[n][m] = maxPath;
        return maxPath;
    }
};
