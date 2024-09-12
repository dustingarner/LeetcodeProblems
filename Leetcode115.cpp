class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.length()<t.length()){
            return 0;
        }   
        if(s==t){
            return 1;
        }
        vector<vector<int>> memo (s.length(), vector<int> (t.length(), -1));
        int lastT = t.length()-1;
        memo[s.length()-1][lastT] = s[s.length()-1]==t[lastT];
        for(int i=s.length()-2; i>=0; --i){
            memo[i][lastT] = (s[i]==t[lastT]) + memo[i+1][lastT];
        }
        int distinct = findDistinct(s, 0, t, 0, memo);
        return distinct;
    }

    int findDistinct(string& s, int sInd, string& t, int tInd, vector<vector<int>>& memo){
        if(sInd>=s.length() || tInd>=t.length()){
            return 0;
        }
        if(memo[sInd][tInd]!=-1){
            return memo[sInd][tInd];
        }
        if(s.length()-sInd < t.length()-tInd){
            memo[sInd][tInd] = 0;
            return 0;
        }
        int noTake = findDistinct(s, sInd+1, t, tInd, memo);
        if(s[sInd]!=t[tInd]){
            memo[sInd][tInd] = noTake;
            return noTake;
        }
        int take = findDistinct(s, sInd+1, t, tInd+1, memo);
        memo[sInd][tInd] = take+noTake;
        return memo[sInd][tInd];
    }
};
