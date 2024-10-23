class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum, int currentSum=0) {
        if(root == nullptr){
            return false;
        }
        currentSum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            return targetSum == currentSum;
        }
        bool hasPath = false;
        if(root->left != nullptr){
            hasPath = hasPath || hasPathSum(root->left, targetSum, currentSum);
        }
        if(root->right != nullptr){
            hasPath = hasPath || hasPathSum(root->right, targetSum, currentSum);
        }
        return hasPath;
    }
};
