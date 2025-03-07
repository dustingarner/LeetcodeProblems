class Solution {
public:
    bool isPrime(int num){
        if(num == 1){
            return false;
        }
        if(num == 2 || num == 3){
            return true;
        }
        for(int i = 2; i <= sqrt(num); ++i){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int currentPrime = -1;
        int num1 = 0, num2 = INT_MAX;
        for(int i = left; i <= right; ++i){
            if(currentPrime == -1 && isPrime(i)){
                currentPrime = i;
                continue;
            }
            if(isPrime(i)){
                if(i - currentPrime < num2 - num1){
                    num1 = currentPrime;
                    num2 = i;
                }
                currentPrime = i;
            }
        }
        if(num1 == 0){
            return {-1, -1};
        }
        return {num1, num2};
    }
};
