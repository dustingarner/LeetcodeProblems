class Solution {
public:
    bool judgeSquareSum(int c) {
        if(isSquare(c)){return true;}
        int a = 1;
        while(a <= sqrt(c/2)){
            int aSquared = a*a;
            int bSquared = c - aSquared;
            if(isSquare(bSquared)){
                return true;
            }
            a++;
        }
        return false;
    }

    bool isSquare(int c){
        if(c == 0){return true;}
        double root = sqrt(c);
        int root_floor = floor(root);
        return c / root_floor == root_floor && c%root_floor == 0;
    }
};
