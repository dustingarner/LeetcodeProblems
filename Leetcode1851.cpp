class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<vector<int>> queriesPlus;
        for(int i=0; i<queries.size(); ++i){
            queriesPlus.push_back({queries[i], i, INT_MAX});
        }
        sort(intervals.begin(), intervals.end());
        sort(queriesPlus.begin(), queriesPlus.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int startPoint = 0;
        for(int i=0; i<queriesPlus.size(); ++i){
            while(startPoint<intervals.size() && intervals[startPoint][0]<=queriesPlus[i][0]){
                int l = intervals[startPoint][0], r = intervals[startPoint][1];
                pq.push({r-l+1, r});
                startPoint++;
            }
            while(!pq.empty() && pq.top()[1]<queriesPlus[i][0]){
                pq.pop();
            }
            if(pq.empty()){
                continue;
            }
            queriesPlus[i][2] = pq.top()[0];
        }
        sort(queriesPlus.begin(), queriesPlus.end(), [](vector<int>& a, vector<int>& b){return b[1]>a[1];});
        vector<int> minimums;
        for(auto x:queriesPlus){
            minimums.push_back(x[2]==INT_MAX ? -1 : x[2]);
        }
        return minimums;
    }
};
