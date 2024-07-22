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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inLocs;
        for(int i=0; i<inorder.size(); ++i){
            inLocs[inorder[i]] = i;
        }
        return recurseTree(preorder, inorder, 0, preorder.size(), 0, inorder.size(), inLocs);
    }

    TreeNode* recurseTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd,
            int inStart, int inEnd, unordered_map<int, int>& inLocs){
        if(preEnd-preStart==0 || inEnd-inStart==0){return nullptr;}
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preEnd-preStart==1 || inEnd-inStart==1){return root;}
        int inIndex = inLocs[root->val];
        int leftWindow = inIndex - inStart;
        int rightPreStart = preStart + leftWindow + 1;
        root->left = recurseTree(preorder, inorder, preStart+1, rightPreStart, inStart, inIndex, inLocs);
        root->right = recurseTree(preorder, inorder, rightPreStart, preEnd, inIndex+1, inEnd, inLocs);
        return root;
    }
};
