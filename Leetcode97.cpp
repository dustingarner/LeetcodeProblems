class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length()+s2.length()){
            return false;
        }
        if(s1.length()==0){
            return s2==s3;
        }
        if(s2.length()==0){
            return s1==s3;
        }
        vector<vector<int>> memo (s1.length()+1, vector<int> (s2.length()+1, 0));
        memo[s1.length()-1][s2.length()] = s1[s1.length()-1]==s3[s3.length()-1] ? 2 : 1;
        memo[s1.length()][s2.length()-1] = s2[s2.length()-1]==s3[s3.length()-1] ? 2 : 1;
        findInterleaves(s1, 0, s2, 0, s3, memo);
        return memo[0][0]==2;
    }

    void findInterleaves(string& s1, int ind1, string& s2, int ind2, string& s3, vector<vector<int>>& memo){
        int ind3 = ind1+ind2;
        if(ind3>s3.length()){
            return;
        }
        if(memo[ind1][ind2]!=0){
            return;
        }
        bool canDo = false;
        if(ind1<s1.length() && s1[ind1]==s3[ind3]){
            findInterleaves(s1, ind1+1, s2, ind2, s3, memo);
            canDo = canDo || memo[ind1+1][ind2]==2;
        }
        if(ind2<s2.length() && s2[ind2]==s3[ind3]){
            findInterleaves(s1, ind1, s2, ind2+1, s3, memo);
            canDo = canDo || memo[ind1][ind2+1]==2;
        }
        memo[ind1][ind2] = canDo ? 2 : 1;
    }
};
