class Solution {
public:
    int maximum69Number (int num) {
        int maxMultiplier = 0;
        int multiplier = 1;
        int temp = num;
        while(temp > 0){
            if(temp%10 == 6){
                maxMultiplier = multiplier;
            }
            temp /= 10;
            multiplier++;
        }
        if(maxMultiplier==0){
            return num;
        }
        return num + pow(10, maxMultiplier-1)*3;
    }
};
