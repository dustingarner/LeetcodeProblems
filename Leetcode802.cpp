class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeness (graph.size(), -1);
        vector<int> safeNodes;
        for(int i = 0; i < graph.size(); ++i){
            if(isSafe(i, graph, safeness)){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }

    bool isSafe(int index, vector<vector<int>>& graph, vector<int>& safeness){
        // -1: Haven't checked, 0: Unsafe, 1: Safe, 2: Currently checking
        if(safeness[index] == 1){
            return true;
        }
        if(safeness[index] == 0){
            return false;
        }
        if(safeness[index] == 2){
            safeness[index] = 0;
            return false;
        }
        safeness[index] = 2;
        bool allSafe = true;
        for(int i = 0; i < graph[index].size(); ++i){
            allSafe = allSafe && isSafe(graph[index][i], graph, safeness);
            if(!allSafe){
                break;
            }
        }
        safeness[index] = allSafe ? 1 : 0;
        return allSafe;
    }
};
