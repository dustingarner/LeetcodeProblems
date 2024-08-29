class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int currentFirst = intervals[0][0];
        vector<int> currentInterval = intervals[0];
        int removed = 0;
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i][0]==currentFirst){
                removed++;
                continue;
            }
            currentFirst = intervals[i][0];
            if(currentInterval[1]<=intervals[i][0]){
                currentInterval = intervals[i];
                continue;
            }
            currentInterval = intervals[i][1]>currentInterval[1] ? currentInterval : intervals[i];
            removed++;
        }
        return removed;
    }
};
