class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int minCount = INT_MAX;
        vector<unordered_map<int, int>> valueMin (coins.size(), unordered_map<int, int>());
        getChange(0, amount, coins, valueMin, minCount, 0);
        return valueMin[0][amount];
    }

    void getChange(int index, int goalValue, const vector<int>& coins, 
            vector<unordered_map<int, int>>& valueMin, int& minCount, int insertedCoins){
        if(index>=coins.size()){
            return;
        }
        if(valueMin[index].find(goalValue)!=valueMin[index].end()){
            return;
        }
        if(goalValue==0){
            valueMin[index][goalValue] = 0;
            return;
        }
        int coin = coins[index];
        if(index==coins.size()-1){
            valueMin[index][goalValue] = goalValue%coin==0 ? goalValue/coin : -1;
            return;
        }
        valueMin[index][goalValue] = -1;
        int multiplier = 0;
        while(multiplier*coin <= goalValue && multiplier+insertedCoins < minCount){
            int currentValue = multiplier*coin;
            int nextValue = goalValue-currentValue;
            getChange(index+1, nextValue, coins, valueMin, minCount, multiplier+insertedCoins);
            if(valueMin[index+1][nextValue]==-1 && currentValue<goalValue){
                multiplier++;
                continue;
            }
            int tempMin = valueMin[index+1][nextValue]==-1 ? multiplier : multiplier+valueMin[index+1][nextValue];
            if(valueMin[index][goalValue]==-1){
                valueMin[index][goalValue] = tempMin;
            }
            valueMin[index][goalValue] = min(valueMin[index][goalValue], tempMin);
            minCount = min(minCount, insertedCoins+valueMin[index][goalValue]);
            multiplier++;
        }
    }
};
