class Solution {
public:
    int minimumDeletions(string s) {
        int aCount = 0, bCount = 0;
        int totalDeletions = 0;
        int foundB = false;
        for(int i=0; i<s.length(); ++i){
            if(!foundB && s[i]=='a'){
                continue;
            }
            if(s[i]=='a'){
                aCount++;
            }
            if(s[i]=='b'){
                bCount++;
                foundB = true;
            }
            if(aCount>=bCount){
                aCount = 0;
                totalDeletions += bCount;
                bCount = 0;
                foundB = false;
            }
        }
        totalDeletions += aCount;
        return totalDeletions;
    }
};
