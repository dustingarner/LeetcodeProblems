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
    int goodNodes(TreeNode* root) {
        return recurseNodes(root, root->val);
    }

    int recurseNodes(TreeNode* root, int maxValue){
        int goodCount = 0;
        if(root->val >= maxValue){
            goodCount++;
        }
        if(root->left){
            goodCount += recurseNodes(root->left, max(maxValue, root->val));
        }
        if(root->right){
            goodCount += recurseNodes(root->right, max(maxValue, root->val));
        }
        return goodCount;
    }
};
