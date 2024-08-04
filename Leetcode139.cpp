class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(auto x:wordDict){
            words.insert(x);
        }
        vector<int> seenIndices (s.length(), -1);
        return findBreaks(s, 0, words, seenIndices);
    }

    bool findBreaks(string& s, int index, unordered_set<string>& words, vector<int>& seenIndices){
        if(seenIndices[index]!=-1){
            return seenIndices[index];
        }
        if(index==s.length()-1){
            bool hasEnd = words.find(s.substr(index, 1))!=words.end();
            seenIndices[index] = hasEnd;
            return hasEnd;
        }
        if(words.find(s.substr(index, s.length()-index))!=words.end()){
            seenIndices[index] = 1;
            return true;
        }
        for(int i=index+1; i<s.length(); ++i){
            string tempSubst = s.substr(index, i-index);
            if(words.find(tempSubst)==words.end()){
                continue;
            }
            bool hasBreak = findBreaks(s, i, words, seenIndices);
            if(hasBreak){
                seenIndices[index] = 1;
                return true;
            }
        }
        seenIndices[index] = 0;
        return false;
    }
};
