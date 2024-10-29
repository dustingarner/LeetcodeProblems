class Solution {
public:
    int lengthOfLastWord(string s) {
        int currentWord = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' '){
                continue;
            }
            if(i == 0 || s[i-1] == ' '){
                currentWord = 0;
            }
            currentWord++;
        }
        return currentWord;
    }
};
