class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0; i<board[0].size(); ++i){
            if(board[0][i]=='O'){
                bfsUnsurroundable(board, make_pair(0, i));
            }
            if(board[board.size()-1][i]=='O'){
                bfsUnsurroundable(board, make_pair(board.size()-1, i));
            }
        }
        for(int i=0; i<board.size(); ++i){
            if(board[i][0]=='O'){
                bfsUnsurroundable(board, make_pair(i, 0));
            }
            if(board[i][board[0].size()-1]=='O'){
                bfsUnsurroundable(board, make_pair(i, board[0].size()-1));
            }
        }
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                board[i][j] = board[i][j]=='Y' ? 'O' : 'X';
            }
        }
    }

    void bfsUnsurroundable(vector<vector<char>>& board, pair<int, int> coord){
        int n = coord.first, m = coord.second;
        queue<pair<int, int>> breadth;
        board[n][m] = 'Y';
        breadth.push(coord);
        vector<int> directions = {0, -1, 0, 1, 0};
        while(!breadth.empty()){
            auto currentCoord = breadth.front();
            n = currentCoord.first;
            m = currentCoord.second;
            for(int i=1; i<directions.size(); ++i){
                int nextN = n+directions[i], nextM = m+directions[i-1];
                if(nextN<0 || nextM<0 || nextN>=board.size() || nextM>=board[0].size()){
                    continue;
                }
                if(board[nextN][nextM]!='O'){
                    continue;
                }
                board[nextN][nextM] = 'Y';
                breadth.push(make_pair(nextN, nextM));
            }
            breadth.pop();
        }
    }
};
