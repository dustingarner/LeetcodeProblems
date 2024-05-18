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
    TreeNode* removeLeafNodes(TreeNode* root, int target, TreeNode* parent=nullptr) {
        if(root==nullptr){return nullptr;}
        root->left = removeLeafNodes(root->left, target, root);
        root->right = removeLeafNodes(root->right, target, root);
        if(root->val == target && root->left == nullptr && root->right == nullptr){
            if(parent!=nullptr){delete root;}
            return nullptr;
        }
        return root;
    }
};
