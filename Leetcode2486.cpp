class Solution {
public:
    int appendCharacters(string s, string t) {
        int sPoint = 0, tPoint = 0;
        int counter = 0;
        while(sPoint < s.length()){
            if(s[sPoint] == t[tPoint]){
                sPoint++;
                tPoint++;
                continue;
            }
            sPoint++;
        }
        return t.length() - tPoint;
    }
};
