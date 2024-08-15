class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0){
            return {newInterval};
        }
        vector<vector<int>> newIntervals;
        int start = newInterval[0], end = newInterval[1];
        vector<int> merged = newInterval;
        bool added = false, beginSet = false;
        for(int i=0; i<intervals.size(); ++i){
            if(intervals[i][1]<start || added){
                newIntervals.push_back(intervals[i]);
                continue;
            }
            if(intervals[i][0]>merged[1]){
                newIntervals.push_back(merged);
                added = true;
                newIntervals.push_back(intervals[i]);
                continue;
            }
            if(!beginSet){
                merged[0] = min(start, intervals[i][0]);
                beginSet = true;
            }
            merged[1] = max(end, intervals[i][1]);
        }
        if(!added){
            newIntervals.push_back(merged);
        }
        return newIntervals;
    }
};
