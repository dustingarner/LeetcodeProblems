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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){return true;}
        bool isValid = true;
        if(!isLessThan(root->left, root->val)){return false;}
        if(!isGreaterThan(root->right, root->val)){return false;}
        return isValidBST(root->left) && isValidBST(root->right);
    }

    bool isLessThan(TreeNode* root, int value){
        if(root == nullptr){return true;}
        if(root->val >= value){return false;}
        return isLessThan(root->left, value) && isLessThan(root->right, value);
    }

    bool isGreaterThan(TreeNode* root, int value){
        if(root == nullptr){return true;}
        if(root->val <= value){return false;}
        return isGreaterThan(root->left, value) && isGreaterThan(root->right, value);
    }
};
