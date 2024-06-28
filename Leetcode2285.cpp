class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> importance (n, vector<int> (2, 0));
        for(int i = 0; i < importance.size(); ++i){
            importance[i][1] = i+1;
        }
        for(int i = 0; i < roads.size(); ++i){
            importance[roads[i][0]][0]++;
            importance[roads[i][1]][0]++;
        }
        sort(importance.begin(), importance.end(), 
                [](vector<int>& v1, vector<int>& v2) {return v1[0] < v2[0];});
        for(int i = 1; i <= importance.size(); ++i){
            importance[i-1][0] = i;
        }
        sort(importance.begin(), importance.end(), 
                [](vector<int>& v1, vector<int>& v2) {return v1[1] < v2[1];});
        long long maxValue = 0;
        for(int i = 0; i < roads.size(); ++i){
            maxValue += importance[roads[i][0]][0];
            maxValue += importance[roads[i][1]][0];
        }
        return maxValue;
    }
};
