class Solution {
public:
    int minimumLength(string s) {
        vector<int> charCount (26, 0);
        for(auto x : s){
            charCount[x-'a']++;
        }
        int deleteCount = 0;
        for(int i = 0; i < 26; i++){
            if(charCount[i] < 3){
                continue;
            }
            charCount[i]--;
            charCount[i] -= charCount[i] % 2;
            deleteCount += charCount[i];
        }
        return s.length() - deleteCount;
    }
};
