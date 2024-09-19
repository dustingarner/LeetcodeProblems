class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> seen (n, false);
        unordered_map<int, vector<vector<int>>> graph;
        for(auto x:times){
            if(graph.find(x[0])==graph.end()){
                graph[x[0]] = {};
            }
            graph[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, k});
        int maxTime = 0;
        while(!q.empty()){
            int currentTime = q.top()[0];
            int node = q.top()[1];
            q.pop();
            if(seen[node-1]){
                continue;
            }
            maxTime = max(maxTime, currentTime);
            seen[node-1] = true;
            for(auto x:graph[node]){
                if(seen[x[0]-1]){
                    continue;
                }
                q.push({currentTime+x[1], x[0]});
            }
        }
        for(auto x:seen){
            if(!x){
                return -1;
            }
        }
        return maxTime;
    }
};
