class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto x : wordList){
            words.insert(x);
        }
        if(words.find(endWord) == words.end()){
            return {};
        }
        queue<string> q;
        q.push(beginWord);
        bool foundWord = false;
        unordered_set<string> seen;
        unordered_map<string, vector<string>> connections;
        while(!q.empty() && !foundWord){
            int levelSize = q.size();
            unordered_set<string> tempSeen;
            for(int i = 0; i < levelSize; ++i){
                string currentWord = q.front();
                q.pop();
                words.erase(currentWord);
                for(int j = 0; j < currentWord.length(); ++j){
                    for(char k = 'a'; k <= 'z'; ++k){
                        string newWord = currentWord;
                        newWord[j] = k;
                        if(words.find(newWord) == words.end()){
                            continue;
                        }
                        if(newWord == currentWord){
                            continue;
                        }
                        if(newWord == endWord){
                            foundWord = true;
                        }
                        if(seen.find(newWord) != seen.end()){
                            continue;
                        }
                        if(connections.find(newWord) == connections.end()){
                            connections[newWord] = {};
                        }
                        connections[newWord].push_back(currentWord);
                        if(tempSeen.find(newWord) == tempSeen.end()){
                            tempSeen.insert(newWord);
                            q.push(newWord);
                        }
                    }
                }
            }
            seen.insert(tempSeen.begin(), tempSeen.end());
        }
        if(!foundWord){
            return {};
        }
        vector<string> currentLadder = {endWord};
        vector<vector<string>> ladders;
        dfs(endWord, beginWord, currentLadder, ladders, connections);
        return ladders;
    }
    
    void dfs(string& currentWord, string& beginWord, vector<string>& currentLadder, vector<vector<string>>& ladders,
            unordered_map<string, vector<string>>& connections){
        if(currentWord == beginWord){
            vector<string> reverseLadder = currentLadder;
            reverse(reverseLadder.begin(), reverseLadder.end());
            ladders.push_back(reverseLadder);
            return;
        }
        for(auto x : connections[currentWord]){
            currentLadder.push_back(x);
            dfs(x, beginWord, currentLadder, ladders, connections);
            currentLadder.pop_back();
        }
    }
};
