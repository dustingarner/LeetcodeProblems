class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n, string (n, '.'));
        vector<vector<string>> allBoards;
        addMoves(0, board, allBoards);
        return allBoards;
    }

    void addMoves(int row, vector<string>& board, vector<vector<string>>& allBoards){
        if(row == board.size()){
            allBoards.push_back(board);
            return;
        }
        for(int i=0; i<board[row].size(); ++i){
            if(!isValidMove(board, row, i)){
                continue;
            }
            board[row][i] = 'Q';
            addMoves(row+1, board, allBoards);
            board[row][i] = '.';
        }
    }

    bool isValidMove(vector<string>& board, int row, int column){
        for(int i=row-1; i>=0; --i){
            int offset = row-i;
            if(board[i][column]=='Q'){
                return false;
            }
            if(column-offset>=0 && board[i][column-offset]=='Q'){
                return false;
            }
            if(column+offset<board[i].size() && board[i][column+offset]=='Q'){
                return false;
            }
        }
        return true;
    }
};
