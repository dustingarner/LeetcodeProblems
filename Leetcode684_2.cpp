class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> connections;
        unordered_set<int> tails;
        for(int i = 0; i < edges.size(); ++i){
            int node1 = edges[i][0], node2 = edges[i][1];
            if(connections.find(node1) == connections.end()){
                tails.insert(node1);
                connections[node1] = {{node2, i}};
            }
            else{
                tails.erase(node1);
                connections[node1].push_back({node2, i});
            }
            if(connections.find(node2) == connections.end()){
                tails.insert(node2);
                connections[node2] = {{node1, i}};
            }
            else{
                tails.erase(node2);
                connections[node2].push_back({node1, i});
            }
        }
        if(tails.size() == 0){
            return edges[edges.size() - 1];
        }
        int start = *tails.begin();
        vector<bool> seen (edges.size(), false);
        int cycleStart = -1, maxInd = -1;
        bool complete = false;
        dfs(start, -1, seen, connections, cycleStart, maxInd, complete);
        return edges[maxInd];
    }

    void dfs(int node, int prevNode, 
            vector<bool>& seen, unordered_map<int, vector<pair<int, int>>>& connections, 
            int& cycleStart, int& maxInd, bool& complete){
        seen[node] = true;
        for(auto x: connections[node]){
            int nextNode = x.first, index = x.second;
            if(nextNode == prevNode){
                continue;
            }
            if(seen[nextNode]){
                cycleStart = nextNode;
                maxInd = index;
                return;
            }
            dfs(nextNode, node, seen, connections, cycleStart, maxInd, complete);
            if(complete){
                return;
            }
            if(cycleStart != -1){
                if(node == cycleStart){
                    complete = true;
                }
                maxInd = max(maxInd, index);
                return;
            }
        }
    }
};
