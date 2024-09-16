class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.length()==0){
            return word2.length();
        }
        if(word2.length()==0){
            return word1.length();
        }
        vector<vector<int>> memo (word1.length(), vector<int> (word2.length(), -1));
        bool letterSeen = word1[word1.length()-1]==word2[word2.length()-1];
        memo[word1.length()-1][word2.length()-1] = !letterSeen;
        for(int i=word2.length()-2; i>=0; --i){
            if(!letterSeen && word1[word1.length()-1]==word2[i]){
                letterSeen = true;
                memo[word1.length()-1][i] = memo[word1.length()-1][i+1];
                continue;
            }
            memo[word1.length()-1][i] = memo[word1.length()-1][i+1] + 1;
        }
        findMinDists(word1, word2, {0,0}, memo);
        return memo[0][0];
    }

    int findMinDists(string& word1, string& word2, vector<int> index, vector<vector<int>>& memo){
        int ind1 = index[0], ind2 = index[1];
        if(ind1>=word1.length() || ind2>=word2.length()){
            return INT_MAX-1;
        }
        if(memo[ind1][ind2]!=-1){
            return memo[ind1][ind2];
        }
        bool isSame = word1[ind1]==word2[ind2];
        if(ind2==word2.length()-1){
            int trail = word1.length()-ind1-1 + !isSame;
            int minDist = min(trail, memo[ind1+1][ind2]+1);
            memo[ind1][ind2] = minDist;
            return minDist;
        }
        vector<int> directions = {0, 1, 1, 0};
        int minDist = INT_MAX;
        for(int i=1; i<directions.size(); ++i){
            int extra = i==2 ? !isSame : 1;
            minDist = min(minDist, findMinDists(word1, word2, {ind1+directions[i], ind2+directions[i-1]}, memo)+extra);
        }
        memo[ind1][ind2] = minDist;
        return minDist;
    }
};
