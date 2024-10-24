class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& pointA, const vector<int>& pointB){
            if(pointA[0] == pointB[0]){
                return pointA[1] > pointB[1];
            }
            return pointA[0] < pointB[0];
        });
        int arrowCount = 0;
        int intervalEnd = points[0][1];
        for(int i = 0; i < points.size(); ++i){
            intervalEnd = min(intervalEnd, points[i][1]);
            if(i == points.size()-1){
                arrowCount++;
            }
            if(points[i][0] > intervalEnd){
                arrowCount++;
                intervalEnd = points[i][1];
            }
        }
        return arrowCount;
    }
};
