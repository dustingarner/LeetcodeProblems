class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> viableCandidates (3, false);
        for(auto x:triplets){
            if(x[0]==target[0] && x[1]<=target[1] && x[2]<=target[2]){
                viableCandidates[0] = true;
            }
            if(x[1]==target[1] && x[0]<=target[0] && x[2]<=target[2]){
                viableCandidates[1] = true;
            }
            if(x[2]==target[2] && x[0]<=target[0] && x[1]<=target[1]){
                viableCandidates[2] = true;
            }
        }
        return(viableCandidates[0] && viableCandidates[1] && viableCandidates[2]);
    }
};
