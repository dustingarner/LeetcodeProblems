class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> connections (edges.size()+1);
        for(int i=0; i<edges.size(); ++i){
            int num1 = edges[i][0], num2 = edges[i][1];
            connections[num1].push_back(num2);
            connections[num2].push_back(num1);
        }
        int cycleStart = 0;
        queue<pair<int, int>> bfs;
        bfs.push(make_pair(1, 0));
        vector<bool> seen (edges.size()+1, false);
        while(!bfs.empty()){
            pair<int, int> num = bfs.front();
            bfs.pop();
            if(seen[num.first]){
                cycleStart = num.first;
                break;
            }
            seen[num.first] = true;
            for(auto x:connections[num.first]){
                if(x==num.second){
                    continue;
                }
                bfs.push(make_pair(x, num.first));
            }
        }
        vector<bool> cycle (edges.size()+1);
        bool cycleFound;
        seen = vector<bool> (edges.size()+1, false);
        dfs(cycleStart, cycleStart, 0, cycle, cycleFound, connections, seen);
        vector<int> redundant;
        for(auto x:edges){
            if(cycle[x[0]] && cycle[x[1]]){
                redundant = x;
            }
        }
        return redundant;
    }

    void dfs(int cycleStart, int currentNumber, int recurseCount, vector<bool>& cycle, bool& cycleFound, 
            vector<vector<int>>& connections, vector<bool>& seen){
        if(recurseCount>2 && cycleStart==currentNumber){
            cycleFound = true;
            return;
        }
        if(seen[currentNumber]){
            return;
        }
        seen[currentNumber] = true;
        for(auto x:connections[currentNumber]){
            dfs(cycleStart, x, recurseCount+1, cycle, cycleFound, connections, seen);
            if(cycleFound){
                cycle[currentNumber] = true;
                return;
            }
        }
    }
};
