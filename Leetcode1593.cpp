class Solution {
public:
    int maxSplit = 1;

    int maxUniqueSplit(string s) {
        string currentString = "";
        unordered_set<string> seenWords;
        splitWords(s, 0, 1, currentString, seenWords);
        return maxSplit;
    }

    void splitWords(const string s, int index, int numSplit, string currentString, 
            unordered_set<string>& seenWords){
        if(index == s.length()){
            if(currentString.length() == 0){
                return;
            }
            if(seenWords.find(currentString) != seenWords.end()){
                return;
            }
            maxSplit = max(numSplit, maxSplit);
            return;
        }
        currentString += s[index];
        splitWords(s, index+1, numSplit, currentString, seenWords);
        if(seenWords.find(currentString) != seenWords.end()){
            return;
        }
        seenWords.insert(currentString);
        splitWords(s, index+1, numSplit+1, "", seenWords);
        seenWords.erase(currentString);
    }
};
