class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = 2*n-2;
        time %= cycle;
        if(time < n){
            return time+1;
        }
        return n-(time-n+1);
    }
};
