class Solution {
public:
    string clearDigits(string s) {
        string newString;
        for(int i = 0; i < s.length(); ++i){
            if(!isdigit(s[i])){
                newString.push_back(s[i]);
                continue;
            }
            if(newString.length() == 0){
                continue;
            }
            newString.pop_back();
        }
        return newString;
    }
};
