class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> setBits (n+1);
        setBits[0] = 0;
        for(int i = 1; i <= n; ++i){
            setBits[i] = setBits[i/2] + i%2;
        }
        return setBits;
    }
};
