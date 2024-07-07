class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottles = 0;
        int leftOver = 0;
        while(numBottles > 0){
            totalBottles += numBottles;
            numBottles += leftOver;
            leftOver = 0;
            leftOver += numBottles % numExchange;
            numBottles /= numExchange;
        }
        return totalBottles;
    }
};
