class Solution {
public:
    bool isSymmetrical(int num){
        int digitCount = 0;
        int tempNum = num;
        while(tempNum > 0){
            tempNum /= 10;
            digitCount++;
        }
        if(digitCount % 2 == 1){
            return false;
        }
        int firstHalf = 0, secondHalf = 0;
        for(int i = 0; i < digitCount; ++i){
            if(i < digitCount / 2){
                firstHalf += num % 10;
            }
            else{
                secondHalf += num % 10;
            }
            num /= 10;
        }
        return firstHalf == secondHalf;
    }

    int countSymmetricIntegers(int low, int high) {
        int symCount = 0;
        for(int i = low; i <= high; ++i){
            if(isSymmetrical(i)){
                symCount++;
            }
        }
        return symCount;
    }
};
