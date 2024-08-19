class Solution {
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        int minAmount = INT_MAX;
        for(int i=2; i<=sqrt(n); ++i){
            if(n%i == 0){
                minAmount = min(minSteps(i) + minSteps(n/i), minAmount);
            }
        }
        if(minAmount==INT_MAX){
            return n;
        }
        return minAmount;
    }
};
