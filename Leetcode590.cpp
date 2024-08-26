class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> order;
        dfs(root, order);
        return order;
    }

    void dfs(Node* root, vector<int>& order){
        if(root==nullptr){
            return;
        }
        for(auto x:root->children){
            dfs(x, order);
        }
        order.push_back(root->val);
    }
};
