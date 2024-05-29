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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> longestPaths = getLongestPaths(root);
        return max(longestPaths.first, longestPaths.second) - 1;
    }

    pair<int, int> getLongestPaths(TreeNode* root){
        if(root == nullptr){return make_pair(0,0);}
        pair<int, int> longestPaths;
        pair<int, int> left = getLongestPaths(root->left);
        pair<int, int> right = getLongestPaths(root->right);
        int pathThroughRoot = left.second + right.second + 1;
        longestPaths.first = max(max(left.first, right.first), pathThroughRoot);
        longestPaths.second = max(left.second, right.second) + 1;
        return longestPaths;
    }
};
