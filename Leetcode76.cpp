class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> originalCounts (52, 0);
        vector<int> currentCounts (52, 0);
        for(auto x : t){
            int letterInd = getLetterInd(x);
            originalCounts[letterInd]++;
            currentCounts[letterInd]++;
        }

        int letterCount = t.length();
        int l = 0, r = 0;
        for(int i = 0; i < s.length(); ++i){
            r = i;
            int letterInd = getLetterInd(s[i]);
            if(originalCounts[letterInd] == 0){
                continue;
            }
            currentCounts[letterInd]--;
            if(currentCounts[letterInd] >= 0){
                letterCount--;
            }
            if(letterCount == 0){
                break;
            }
        }
        if(letterCount > 0){
            return "";
        }

        int minSize = r-l+1;
        int minStart = 0;
        while(l < s.length()){
            int letterInd = getLetterInd(s[l]);
            if(originalCounts[letterInd] > 0){
                currentCounts[letterInd]++;
                if(currentCounts[letterInd] > 0){
                    letterCount++;
                }
            }
            l++;
            if(letterCount > 0){
                r++;
                if(r >= s.length()){
                    break;
                }
                letterInd = getLetterInd(s[r]);
                if(originalCounts[letterInd] > 0){
                    currentCounts[letterInd]--;
                    if(currentCounts[letterInd] >= 0){
                        letterCount--;
                    }
                }
            }
            if(letterCount == 0){
                minSize = r-l+1;
                minStart = l;
            }
        }
        return s.substr(minStart, minSize);
    }

    int getLetterInd(char letter){
        if(islower(letter)){
            return letter-'a';
        }
        return letter-'A'+26;
    }
};
