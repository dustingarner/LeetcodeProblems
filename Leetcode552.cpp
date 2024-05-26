class Solution {
public:
    static const int MOD = 1000000007;

    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, 
                vector<int>(3, -1)));
        return numCombos(n, 0, 0, memo);
    }

    int numCombos(int n, int numAbsents, int numLates, 
            vector<vector<vector<int>>>& memo){
        if(n==0){return 1;}
        if(memo[n-1][numAbsents][numLates] != -1){
            return memo[n-1][numAbsents][numLates];
        }
        int totalCombos = 0;
        for(auto x : "ALP"){        
            if(x=='A' && numAbsents==1){continue;}
            else if(x=='A'){
                totalCombos += numCombos(n-1, 1, 0, memo);
            }
            else if(x=='L' && numLates==2){continue;}
            else if(x=='L'){
                totalCombos += numCombos(n-1, numAbsents, numLates+1, memo);
            }
            else if(x=='P'){
                totalCombos += numCombos(n-1, numAbsents, 0, memo);
            }
            totalCombos %= MOD;
        }
        memo[n-1][numAbsents][numLates] = totalCombos;
        return totalCombos;
    }
};
