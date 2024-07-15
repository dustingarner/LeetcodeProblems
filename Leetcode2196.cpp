/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, int> parents;
        for(auto x : descriptions){
            int valParent = x[0];
            int valChild = x[1];
            bool isLeft = x[2];
            if(nodes.find(valParent) == nodes.end()){
                nodes[valParent] = new TreeNode(valParent);
                parents[valParent] = -1;
            }
            if(nodes.find(valChild) == nodes.end()){
                nodes[valChild] = new TreeNode(valChild);
            }
            parents[valChild] = valParent;
            if(isLeft){
                nodes[valParent]->left = nodes[valChild];
            }
            else{
                nodes[valParent]->right = nodes[valChild];
            }
        }
        int rootVal = descriptions[0][0];
        while(parents[rootVal] != -1){
            rootVal = parents[rootVal];
        }
        return nodes[rootVal];
    }
};
