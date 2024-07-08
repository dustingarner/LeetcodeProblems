class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> seen (board.size(), vector<bool> (board[0].size(), false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(checkBoard(board, word, seen, make_pair(i, j))){
                    return true;
                }
            }
        }
        return false;
    }

    bool checkBoard(vector<vector<char>>& board, string& word, vector<vector<bool>>& seen, pair<int, int> loc,
            int index=0){
        if(seen[loc.first][loc.second]){return false;}
        char letter = word[index];
        if(board[loc.first][loc.second] != letter){return false;}
        if(index == word.length() - 1){return true;}
        seen[loc.first][loc.second] = true;
        if(loc.first > 0){
            if(checkBoard(board, word, seen, make_pair(loc.first-1, loc.second), index+1)){return true;}
        }
        if(loc.first < board.size()-1){
            if(checkBoard(board, word, seen, make_pair(loc.first+1, loc.second), index+1)){return true;}
        }
        if(loc.second > 0){
            if(checkBoard(board, word, seen, make_pair(loc.first, loc.second-1), index+1)){return true;}
        }
        if(loc.second < board[0].size()-1){
            if(checkBoard(board, word, seen, make_pair(loc.first, loc.second+1), index+1)){return true;}
        }
        seen[loc.first][loc.second] = false;
        return false;
    }
};
