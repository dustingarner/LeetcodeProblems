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
    int distributeCoins(TreeNode* root) {
        if(root==nullptr){return 0;}
        int numMoves = 0;
        int neededLeft = netValue(root->left);
        int neededRight = netValue(root->right);
        int leftMoves = distributeCoins(root->left) + abs(neededLeft);
        int rightMoves = distributeCoins(root->right) + abs(neededRight);
        return leftMoves + rightMoves;
    }

    int netValue(TreeNode* root){
        if(root==nullptr){return 0;}
        int quantity = root->val - 1;
        quantity += netValue(root->left);
        quantity += netValue(root->right);
        return quantity;
    }
};
