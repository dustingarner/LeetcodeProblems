class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo (s.length(), vector<int> (p.length(), -1));
        bool findMatch = checkMatch(s, p, 0, 0, memo);
        return findMatch;
    }

    bool checkMatch(string& s, string& p, int sInd, int pInd, vector<vector<int>>& memo){
        if(sInd>=s.length() && pInd>=p.length()){
            return true;
        }
        if(sInd>=s.length()){
            return checkTail(p, pInd);
        }
        if(pInd>=p.length()){
            return false;
        }
        if(memo[sInd][pInd]!=-1){
            return memo[sInd][pInd];
        }
        bool nextIsStar = pInd==p.length()-1 ? false : p[pInd+1]=='*';
        if(nextIsStar){
            memo[sInd][pInd] = checkMatch(s, p, sInd, pInd+1, memo);
            return memo[sInd][pInd];
        }
        char sChar = s[sInd], pChar = p[pInd];
        if(pChar!='*' && pChar!='.' && sChar!=pChar){
            memo[sInd][pInd] = false;
            return memo[sInd][pInd];
        }
        if(sChar==pChar || pChar=='.'){
            memo[sInd][pInd] = checkMatch(s, p, sInd+1, pInd+1, memo);
            return memo[sInd][pInd];
        }
        bool isStarMatch = false;
        char prevChar = p[pInd-1];
        isStarMatch = isStarMatch || checkMatch(s, p, sInd, pInd+1, memo);
        if(prevChar==sChar || prevChar=='.'){
            isStarMatch = isStarMatch || checkMatch(s, p, sInd+1, pInd+1, memo);
            isStarMatch = isStarMatch || checkMatch(s, p, sInd+1, pInd, memo);
        }
        memo[sInd][pInd] = isStarMatch;
        return isStarMatch;
    }

    bool checkTail(string& p, int pInd){
        if(pInd>=p.length()){
            return true;
        }
        if(pInd==p.length()-1){
            return p[pInd]=='*';
        }
        if(p[pInd]=='*'){
            return checkTail(p, pInd+1);
        }
        return p[pInd+1]=='*' && checkTail(p, pInd+1);
    }
};
