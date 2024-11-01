class Solution {
public:
    string makeFancyString(string s) {
        int consecutiveCount = 1;
        string fancyString (1, s[0]);
        for(int i = 1; i < s.length(); ++i){
            consecutiveCount = s[i] == s[i-1] ? consecutiveCount + 1 : 1;
            if(consecutiveCount > 2){
                continue;
            }
            fancyString.push_back(s[i]);
        }
        return fancyString;
    }
};
