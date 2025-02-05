class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        int firstDiff = -1;
        int diffCount = 0;
        for(int i = 0; i < s1.length(); ++i){
            if(s1[i] == s2[i]){
                continue;
            }
            diffCount++;
            if(diffCount > 2){
                return false;
            }
            if(diffCount == 1){
                firstDiff = i;
                continue;
            }
            if(s1[firstDiff] != s2[i] || s2[firstDiff] != s1[i]){
                return false;
            }
        }
        return diffCount != 1;
    }
};
