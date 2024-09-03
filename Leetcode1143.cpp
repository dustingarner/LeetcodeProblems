class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo (text1.length(), vector<int> (text2.length(), -1));
        return longestRecurse(text1, text2, 0, 0, memo);
    }

    int longestRecurse(string& text1, string& text2, int index1, int index2, vector<vector<int>>& memo){
        if(index1>=text1.length() || index2>=text2.length()){
            return 0;
        }
        if(memo[index1][index2]!=-1){
            return memo[index1][index2];
        }
        int length = 0;
        if(text1[index1]==text2[index2]){
            length++;
            length += longestRecurse(text1, text2, index1+1, index2+1, memo);
        }
        else{
            length += max(longestRecurse(text1, text2, index1+1, index2, memo),
                    longestRecurse(text1, text2, index1, index2+1, memo));
        }
        memo[index1][index2] = length;
        return length;
    }
};
