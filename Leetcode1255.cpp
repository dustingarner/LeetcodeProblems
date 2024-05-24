class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> quantities(26, 0);
        for(auto &i : letters){
            quantities[i - 'a']++;
        }
        int maxScore = 0;
        backtrack(words, letters, score, quantities, 0, maxScore, 0);
        return maxScore;
    }

    void backtrack(vector<string>& words, vector<char>& letters, vector<int>& score,
            vector<int> quantities, int index, int& maxScore, int tempScore){
        for(auto &i : quantities){
            if(i<0){
                return;
            }
        }
        maxScore = max(maxScore, tempScore);
        for(int i = index; i < words.size(); i++){
            int wordScore = 0;
            for(int j = 0; j < words[i].length(); j++){
                int letterIndex = words[i][j] - 'a';
                quantities[letterIndex]--;
                wordScore += score[letterIndex];
            }
            backtrack(words, letters, score, quantities, i+1, maxScore, 
                    tempScore+wordScore);
            for(int j = 0; j < words[i].length(); j++){
                int letterIndex = words[i][j] - 'a';
                quantities[letterIndex]++;
            }
        }

    }
};
