class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<bool> seenInA (A.size(), false);
        vector<bool> seenInB (B.size(), false);
        vector<int> C (A.size(), 0);
        for(int i = 0; i < A.size(); ++i){
            seenInA[A[i]-1] = true;
            seenInB[B[i]-1] = true;
            if(seenInA[B[i]-1]){
                C[i]++;
            }
            if(seenInB[A[i]-1] && A[i] != B[i]){
                C[i]++;
            }
            if(i > 0){
                C[i] += C[i-1];
            }
        }
        return C;
    }
};
