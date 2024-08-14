class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        unordered_set<string> words;
        for(auto x:wordList){
            words.insert(x);
        }
        while(!q.empty()){
            string word = q.front().first;
            int depth = q.front().second;
            if(word==endWord){
                return depth;
            }
            q.pop();
            for(int i=0; i<word.length(); ++i){
                for(int j=0; j<26; ++j){
                    string tempWord = word;
                    tempWord[i] = j+'a';
                    if(words.find(tempWord)!=words.end()){
                        q.push(make_pair(tempWord, depth+1));
                        words.erase(tempWord);
                    }
                }
            }
        }
        return 0;
    }
};
