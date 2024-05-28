/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){return nullptr;}
        Node* newNode = new Node;
        newNode->val = node->val;
        unordered_map<int, Node*> seenNodes;
        cloneNodes(newNode, node, seenNodes);
        return newNode;
    }
    void cloneNodes(Node* newNode, Node* oldNode, unordered_map<int, Node*>& seenNodes){
        seenNodes[newNode->val] = newNode;
        for(int i = 0; i < oldNode->neighbors.size(); i++){
            int neighborVal = oldNode->neighbors[i]->val;
            if(seenNodes.find(neighborVal) != seenNodes.end()){
                newNode->neighbors.push_back(seenNodes[neighborVal]);
                continue;
            }
            Node* newNeighbor = new Node;
            newNeighbor->val = neighborVal;
            cloneNodes(newNeighbor, oldNode->neighbors[i], seenNodes);
            newNode->neighbors.push_back(newNeighbor);
        }
    }
};
