class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charFreqs (26, 0);
        for(auto x:magazine){
            charFreqs[x-'a']++;
        }
        for(auto x:ransomNote){
            charFreqs[x-'a']--;
            if(charFreqs[x-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};
