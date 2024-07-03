class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){return 1.0;}
        if(n < 0){
            x = 1/x;
            n = abs(n);
        }
        if(n == 1){return x;}
        if(n == 2){return x*x;}
        double extra = (n%2 == 0) ? 1 : x;
        double halfPower = myPow(x, n/2);
        return halfPower * halfPower * extra;
    }
};
