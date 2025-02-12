class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSums;
        int maxSum = -1;
        for(auto x:nums){
            int currentSum = sumOfDigits(x);
            if(digitSums.find(currentSum) == digitSums.end()){
                digitSums[currentSum] = x;
                continue;
            }
            maxSum = max(maxSum, x+digitSums[currentSum]);
            digitSums[currentSum] = max(digitSums[currentSum], x);
        }
        return maxSum;
    }

    int sumOfDigits(int num){
        int digitSum = 0;
        while(num > 0){
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }
};
