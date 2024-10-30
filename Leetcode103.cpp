class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> order;
        vector<int> currentLevel;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            if(level > order.size()){
                if(level % 2 == 0){
                    reverse(currentLevel.begin(), currentLevel.end());
                }
                order.push_back(currentLevel);
                currentLevel.clear();
            }
            q.pop();
            if(node == nullptr){
                continue;
            }
            currentLevel.push_back(node->val);
            q.push({node->left, level+1});
            q.push({node->right, level+1});
        }
        return order;
    }
};
