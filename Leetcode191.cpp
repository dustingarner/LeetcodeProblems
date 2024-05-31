class Solution {
public:
    int hammingWeight(int n) {
        int setBitCount = 0;
        while(n > 0){
            if(n & 1){
                setBitCount++;
            }
            n >>= 1;
        }
        return setBitCount;
    }
};
