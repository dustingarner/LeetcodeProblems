class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWaitingTime = 0.0;
        int currentTime = customers[0][0];
        for(int i = 0; i < customers.size(); ++i){
            currentTime = currentTime > customers[i][0] ? currentTime : customers[i][0];
            currentTime += customers[i][1];
            totalWaitingTime += currentTime - customers[i][0];
        }
        return totalWaitingTime / (double)customers.size();
    }
};
