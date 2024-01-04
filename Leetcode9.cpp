class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        if(x < 10){
            return true;
        }
        int num = x;
        long long reversed = 0;
        while(num != 0){
            int tempDig = num%10;
            num -= tempDig;
            num /= 10;
            reversed = (reversed * 10) + tempDig;
        }
        return reversed == x;
    }
};
