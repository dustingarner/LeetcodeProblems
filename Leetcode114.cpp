class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        flatten(root->right);
        if(root->left == nullptr){
            return;
        }
        flatten(root->left);
        TreeNode* branch = root->right;
        root->right = root->left;
        root->left = nullptr;
        if(branch == nullptr){
            return;
        }
        insertAtEnd(root->right, branch);
    }

    void insertAtEnd(TreeNode* root, TreeNode* branch){
        if(root->right == nullptr){
            root->right = branch;
            return;
        }
        insertAtEnd(root->right, branch);
    }
};
