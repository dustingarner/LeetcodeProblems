class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> lucky;
        vector<int> rowMins (matrix.size(), 0);
        for(int i=0; i<matrix.size(); ++i){
            for(int j=1; j<matrix[i].size(); ++j){
                if(matrix[i][j] < matrix[i][rowMins[i]]){
                    rowMins[i] = j;
                }
            }
        }
        for(int j=0; j<matrix[0].size(); ++j){
            int columnMax = 0;
            for(int i=1; i<matrix.size(); ++i){
                if(matrix[i][j] > matrix[columnMax][j]){
                    columnMax = i;
                }
            }
            if(matrix[columnMax][j] == matrix[columnMax][rowMins[columnMax]]){
                lucky.push_back(matrix[columnMax][j]);
            }
        }
        return lucky;
    }
};
