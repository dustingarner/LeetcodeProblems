class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rows (matrix.size(), false);
        vector<bool> columns(matrix[0].size(), false);
        vector<pair<int, int>> convert;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                if(matrix[i][j]==0){
                    convert.push_back(make_pair(i, j));
                }
            }
        }
        for(auto x:convert){
            makeCross(x, matrix, rows, columns);
        }
    }

    void makeCross(pair<int, int>& coord, vector<vector<int>>& matrix, vector<bool>& rows, 
            vector<bool>& columns){
        int n = coord.first, m = coord.second;
        if(!rows[n]){
            rows[n] = true;
            for(int i=0; i<matrix[n].size(); ++i){
                matrix[n][i] = 0;
            }
        }
        if(!columns[m]){
            columns[m] = true;
            for(int i=0; i<matrix.size(); ++i){
                matrix[i][m] = 0;
            }
        }
    }
};
