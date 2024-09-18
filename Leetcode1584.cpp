class Solution {
public:
    int getDistance(vector<int>& point1, vector<int>& point2){
        return abs(point1[0]-point2[0]) + abs(point1[1]-point2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_set<int> seenPoints;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        int cost = 0;
        q.push({0, 0});
        while(!q.empty()){
            int distance = q.top()[0], index = q.top()[1];
            q.pop();
            if(seenPoints.find(index)!=seenPoints.end()){
                continue;
            }
            cost += distance;
            seenPoints.insert(index);
            for(int i=0; i<points.size(); ++i){
                if(seenPoints.find(i)!=seenPoints.end()){
                    continue;
                }
                int nextDistance = getDistance(points[index], points[i]);
                q.push({nextDistance, i});
            }
        }
        return cost;
    }
};
