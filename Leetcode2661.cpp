class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> rows (n, 0);
        vector<int> columns (m, 0);
        vector<vector<int>> locations (m * n, vector<int> (2, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                locations[mat[i][j] - 1] = {i, j};
            }
        }
        for(int i = 0; i < arr.size(); ++i){
            int row = locations[arr[i] - 1][0], column = locations[arr[i] - 1][1];
            rows[row]++;
            if(rows[row] == m){
                return i;
            }
            columns[column]++;
            if(columns[column] == n){
                return i;
            }
        }
        return arr.size()-1;
    }
};
