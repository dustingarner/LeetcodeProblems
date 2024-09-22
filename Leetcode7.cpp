class Solution {
public:
    int reverse(int x) {
        int sign = x<0 ? -1 : 1;
        int newNum = 0;
        while(x!=0){
            if(INT_MAX/10 < newNum || INT_MIN/10 > newNum){
                return 0;
            }
            newNum *= 10;
            newNum += (x%(10*sign));
            x /= 10;
        }
        return newNum;
    }
};
