class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diffBits = start^goal;
        int bitCount = 0;
        while(diffBits>0){
            bitCount += diffBits&1;
            diffBits >>= 1;
        }
        return bitCount;
    }
};
