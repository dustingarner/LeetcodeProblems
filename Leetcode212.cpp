class TrieNode{
public:
    string completeWord = "";
    TrieNode* nextNodes[26] = {nullptr};

    ~TrieNode(){
        for(auto x:nextNodes){
            if(x==nullptr){
                continue;
            }
            delete x;
        }
    }

    void addWord(string& word, int index){
        if(index==word.length()){
            completeWord = word;
            return;
        }
        int charIndex = word[index]-'a';
        if(nextNodes[charIndex]==nullptr){
            nextNodes[charIndex] = new TrieNode();
        }
        nextNodes[charIndex]->addWord(word, index+1);
    }

    bool findWord(string& word, int index){
        if(index==word.length()){
            return true;
        }
        int charIndex = word[index]-'a';
        if(nextNodes[charIndex]==nullptr){
            return false;
        }
        return nextNodes[charIndex]->findWord(word, index+1);
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();
        for(auto x:words){
            trie->addWord(x, 0);
        }
        vector<string> foundWords;
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                vector<vector<bool>> seenSpots (board.size(), vector<bool> (board[0].size(), false));
                checkWords(board, make_pair(i, j), trie, seenSpots, foundWords);
            }
        }
        delete trie;
        trie = nullptr;
        return foundWords;
    }

    void checkWords(vector<vector<char>>& board, pair<int, int> coord, TrieNode* node, vector<vector<bool>>& seenSpots,
            vector<string>& foundWords){
        int i = coord.first, j = coord.second;
        if(seenSpots[i][j]){
            return;
        }
        int charIndex = board[i][j]-'a';
        if(node->nextNodes[charIndex]==nullptr){
            return;
        }
        TrieNode* nextNode = node->nextNodes[charIndex];
        if(nextNode->completeWord!=""){
            foundWords.push_back(nextNode->completeWord);
            nextNode->completeWord = "";
        }
        seenSpots[i][j] = true;
        if(i>0){
            checkWords(board, make_pair(i-1, j), nextNode, seenSpots, foundWords);
        }
        if(i<board.size()-1){
            checkWords(board, make_pair(i+1, j), nextNode, seenSpots, foundWords);
        }
        if(j>0){
            checkWords(board, make_pair(i, j-1), nextNode, seenSpots, foundWords);
        }
        if(j<board[0].size()-1){
            checkWords(board, make_pair(i, j+1), nextNode, seenSpots, foundWords);
        }
        seenSpots[i][j] = false;
    }
};
