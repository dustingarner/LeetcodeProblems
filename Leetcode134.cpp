class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int minTank = INT_MAX;
        int minLoc = 0;
        for(int i=0; i<gas.size(); ++i){
            if(tank<minTank){
                minTank = tank;
                minLoc = i;
            }
            tank += gas[i] - cost[i];
        }
        if(tank<0){
            return -1;
        }
        return minLoc;
    }
};
