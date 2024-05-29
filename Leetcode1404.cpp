class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carryOver = 0;
        for(int i = s.length()-1; i > 0; i--){
            int toAdd = carryOver + ((s[i] == '0') ? 0 : 1);
            if(toAdd == 0){
                steps += 1;
            }
            else if(toAdd == 1){
                steps += 2;
                carryOver = 1;
            }
            else{
                steps += 1;
                carryOver = 1;
            }
        
        }
        steps += carryOver;
        return steps;
    }
};
