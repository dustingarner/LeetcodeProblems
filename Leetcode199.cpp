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
    vector<int> rightSideView(TreeNode* root) {
        int height = getHeight(root);
        vector<int> rightSide (height, 0);
        vector<int> indices (height, -1);
        createRightSide(root, 0, 0, rightSide, indices);
        return rightSide;
    }

    void createRightSide(TreeNode* root, int depth, int index, vector<int>& rightSide, vector<int>& indices){
        if(root==nullptr){return;}
        if(index > indices[depth]){
            indices[depth] = index;
            rightSide[depth] = root->val;
        }
        index <<= 1;
        createRightSide(root->left, depth+1, index, rightSide, indices);
        createRightSide(root->right, depth+1, index+1, rightSide, indices);
    }

    int getHeight(TreeNode* root){
        if(root==nullptr){return 0;}
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};
