class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryOver = 1;
        for(int i = digits.size()-1; i >= 0; --i){
            if(digits[i] < 9){
                digits[i] += carryOver;
                carryOver = 0;
                break;
            }
            if(digits[i] == 9){
                digits[i] = 0;
                carryOver = 1;
            }
        }
        if(carryOver == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
