class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int minimized = 0;
        int setBits = 0;
        while(num2 > 0){
            setBits += num2 % 2;
            num2 /= 2;
        }
        int base = 0;
        int num1Clone = num1;
        while(num1Clone > 1){
            base++;
            num1Clone /= 2;
        }
        while(num1 > 0 && setBits > 0){
            int currentPower = pow(2, base);
            if(currentPower & num1){
                minimized += currentPower;
                setBits--;
            }
            num1 %= currentPower;
            base--;
        }
        base = 0;
        while(setBits > 0){
            int currentPower = pow(2, base);
            if(!(minimized & currentPower)){
                minimized += currentPower;
                setBits--;
            }
            base++;
        }
        return minimized;
    }
};
