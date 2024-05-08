class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScores = score;
        sort(sortedScores.begin(), sortedScores.end(), greater<int>());
        unordered_map<int, string> ranks;
        for(int i = 0; i < sortedScores.size(); i++){
            string rank;
            if(i + 1 == 1){
                rank = "Gold Medal";
            }
            else if(i + 1 == 2){
                rank = "Silver Medal";
            }
            else if(i + 1 == 3){
                rank = "Bronze Medal";
            }
            else{
                rank = to_string(i+1);
            }
            ranks[sortedScores[i]] = rank;
        }
        vector<string> relativeScores;
        for(int i = 0; i < score.size(); i++){
            relativeScores.push_back(ranks[score[i]]);
        }
        return relativeScores;
    }
};
