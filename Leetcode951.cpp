class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr){
            return true;
        }
        if(root1 == nullptr || root2 == nullptr){
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }
        bool unflipped = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool flipped = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        return unflipped || flipped;
    }
};
