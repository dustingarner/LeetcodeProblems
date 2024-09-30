class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<vector<int>>> connections;
        for(auto x:flights){
            if(connections.find(x[0])==connections.end()){
                connections[x[0]] = {};
            }
            connections[x[0]].push_back({x[1], x[2]});
        }
        int minPrice = INT_MAX;
        vector<int> seen (n, INT_MAX);
        queue<vector<int>> q;
        q.push({src, 0, -1});
        while(!q.empty()){
            int node = q.front()[0], price = q.front()[1], stops = q.front()[2];
            if(stops>k){
                break;
            }
            q.pop();
            seen[node] = price;
            if(node==dst){
                minPrice = min(minPrice, price);
                continue;
            }
            for(auto x:connections[node]){
                if(seen[x[0]]<=price+x[1]){
                    continue;
                }
                if(price+x[1]>=minPrice){
                    continue;
                }
                if(stops==k){
                    continue;
                }
                q.push({x[0], price+x[1], stops+1});
            }
        }
        return minPrice==INT_MAX ? -1 : minPrice;
    }
};
