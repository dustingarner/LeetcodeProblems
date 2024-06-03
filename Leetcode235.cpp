/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p){return p;}
        if(root == q){return q;}
        int lowerVal = min(p->val, q->val);
        int higherVal = max(p->val, q->val);
        if(root->val > lowerVal && root->val < higherVal){return root;}
        if(root->val > higherVal){return lowestCommonAncestor(root->left, p, q);}
        return lowestCommonAncestor(root->right, p, q);
    }
};
