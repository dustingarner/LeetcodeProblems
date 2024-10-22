class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> directions = {-1, -1, 0, 1, 1, 1, 0, -1, -1, -1};
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                int aliveNeighbors = 0;
                for(int k = 0; k < directions.size()-2; ++k){
                    int nextI = i + directions[k], nextJ = j + directions[k+2];
                    if(nextI < 0 || nextJ < 0 || nextI >= board.size() || nextJ >= board[i].size()){
                        continue;
                    }
                    aliveNeighbors += board[nextI][nextJ] % 2;
                }
                if(!board[i][j] && aliveNeighbors == 3){
                    board[i][j] = 2;
                }
                if(!board[i][j]){
                    continue;
                }
                if(aliveNeighbors != 2 && aliveNeighbors != 3){
                    board[i][j] = 3;
                }
            }
        }
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                if(board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
    }
};
