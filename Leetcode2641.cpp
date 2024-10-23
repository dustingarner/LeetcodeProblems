class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        int depth = getDepth(root, 0);
        vector<long long> sums (depth, 0);
        getSums(root, 0, sums);
        changeValues(root, 0, sums);
        root->val = 0;
        return root;
    }

    int getDepth(TreeNode* root, int depth){
        if(root == nullptr){
            return depth;
        }
        return max(getDepth(root->left, depth+1), getDepth(root->right, depth+1));
    }

    void getSums(TreeNode* root, int depth, vector<long long>& sums){
        if(root == nullptr){
            return;
        }
        sums[depth] += root->val;
        getSums(root->left, depth+1, sums);
        getSums(root->right, depth+1, sums);
    }

    void changeValues(TreeNode* root, int depth, const vector<long long>& sums){
        if(root == nullptr){
            return;
        }
        if(depth == sums.size()-1){
            return;
        }
        long long cousinVal = sums[depth+1];
        cousinVal = root->left == nullptr ? cousinVal : cousinVal - root->left->val;
        cousinVal = root->right == nullptr ? cousinVal : cousinVal - root->right->val;
        if(root->left != nullptr){
            root->left->val = cousinVal;
        }
        if(root->right != nullptr){
            root->right->val = cousinVal;
        }
        changeValues(root->left, depth+1, sums);
        changeValues(root->right, depth+1, sums);
    }
};
