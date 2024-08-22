class Solution {
public:
    int findComplement(int num) {
        int newNum = 0;
        int multiplier = 0;
        while(num!=0){
            newNum += pow(2, multiplier) * ((~num)&1);
            multiplier++;
            num >>= 1;
        }
        return newNum;
    }
};
