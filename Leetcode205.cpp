class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, char> charMap;
        unordered_set<char> seenChars;
        for(int i = 0; i < s.length(); ++i){
            if(charMap.find(s[i]) != charMap.end()){
                if(charMap[s[i]] != t[i]){
                    return false;
                }
                continue;
            }
            if(seenChars.find(t[i]) != seenChars.end()){
                return false;
            }
            charMap[s[i]] = t[i];
            seenChars.insert(t[i]);
        }
        return true;
    }
};
