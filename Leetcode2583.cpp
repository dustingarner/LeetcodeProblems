class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int depth = getDepth(root, 0);
        if(depth < k){
            return -1;
        }
        vector<long long> sums (depth, 0);
        getSums(root, 0, sums);
        sort(sums.begin(), sums.end());
        return sums[sums.size() - k];
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
};
