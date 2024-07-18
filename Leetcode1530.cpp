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
    int countPairs(TreeNode* root, int distance) {
        if(distance==1){return 0;}
        int pairCount = 0;
        dfs(root, pairCount, distance);
        return pairCount;
    }

    vector<int> dfs(TreeNode* root, int& pairCount, const int& distance){
        if(root==nullptr){return {};}
        if(root->left==nullptr && root->right==nullptr){return {1};}
        auto left = dfs(root->left, pairCount, distance);
        auto right = dfs(root->right, pairCount, distance);
        for(auto x : left){
            for(auto y : right){
                if(x+y <= distance){
                    pairCount++;
                }
            }
        }
        vector<int> combined;
        for(auto x : left){
            if(x==distance-1){continue;}
            combined.push_back(x+1);
        }
        for(auto y : right){
            if(y==distance-1){continue;}
            combined.push_back(y+1);
        }
        return combined;
    }
};
