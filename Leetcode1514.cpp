class Solution {
public:
    int endNode;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, 
            int end_node) {
        endNode = end_node;
        unordered_map<int, vector<pair<int, double>>> connections;
        for(int i=0; i<edges.size(); ++i){
            for(auto x:edges[i]){
                if(connections.find(x)==connections.end()){
                    connections[x] = {};
                }
            }
            int edgeA = edges[i][0], edgeB = edges[i][1];
            connections[edgeA].push_back({edgeB, succProb[i]});
            connections[edgeB].push_back({edgeA, succProb[i]});
        }
        unordered_map<int, double> weights;
        weights[start_node] = 1.0;
        dijkstra(start_node, connections, weights);
        if(weights.find(end_node)==weights.end()){
            return 0.0;
        }
        return weights[end_node];
    }

    void dijkstra(int sourceNode, unordered_map<int, vector<pair<int, double>>>& connections,
            unordered_map<int, double>& weights){
        vector<int> q = {sourceNode};
        unordered_map<int, int> indices;
        indices[sourceNode] = 0;
        while(q.size()>0){
            int currentNode = q[0];
            q[0] = q[q.size()-1];
            indices[q[0]] = 0;
            q.pop_back();
            heapifyDown(q[0], weights, q, indices);
            for(auto x:connections[currentNode]){
                int nextNode = x.first;
                if(indices.find(nextNode)!=indices.end() && indices[nextNode]==-1){
                    continue;
                }
                double nextProb = weights[currentNode]*x.second;
                if(weights.find(nextNode)==weights.end()){
                    weights[nextNode] = 0.0;
                    q.push_back(nextNode);
                    indices[nextNode] = q.size()-1;
                }
                if(weights[nextNode]<nextProb){
                    weights[nextNode] = nextProb;
                    heapifyUp(nextNode, weights, q, indices);
                }
            }
            indices[currentNode] = -1;
            if(currentNode==endNode){
                break;
            }
        }
    }

    void heapifyDown(int node, unordered_map<int, double>& weights, vector<int>& q, unordered_map<int, int>& indices){
        int index = indices[node];
        int rightIndex = (index+1)*2;
        int leftIndex = rightIndex-1;
        if(leftIndex>=q.size()){
            return;
        }
        int nextIndex = leftIndex;
        if(rightIndex<q.size()){
            int left = q[leftIndex], right = q[rightIndex];
            nextIndex = weights[left]>weights[right] ? leftIndex : rightIndex;
        }
        int next = q[nextIndex];
        if(weights[node]>weights[next]){
            return;
        }
        q[index] = next;
        indices[next] = index;
        q[nextIndex] = node;
        indices[node] = nextIndex;
        heapifyDown(node, weights, q, indices);
    }

    void heapifyUp(int node, unordered_map<int, double>& weights, vector<int>& q, unordered_map<int, int>& indices){
        int index = indices[node];
        if(index==0){
            return;
        }
        int parentIndex = (index+1)/2-1;
        int parent = q[parentIndex];
        if(weights[node]<=weights[parent]){
            return;
        }
        q[index] = parent;
        indices[parent] = index;
        q[parentIndex] = node;
        indices[node] = parentIndex;
        heapifyUp(node, weights, q, indices);
    }
};
