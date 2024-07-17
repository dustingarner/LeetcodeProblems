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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        addNodes(root, nullptr, true, to_delete, forest, true);
        return forest;
    }

    bool isToDelete(int goal, const vector<int>& to_delete){
        int l = 0, r = to_delete.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            if(to_delete[m]==goal){return true;}
            if(to_delete[m]<goal){l=m+1;}
            if(to_delete[m]>goal){r=m-1;}
        }
        return false;
    }

    void addNodes(TreeNode* root, TreeNode* parent, bool rootIsLeft, const vector<int>& to_delete, 
            vector<TreeNode*>& forest, bool addNode){
        if(root==nullptr){return;}
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        bool addChildren = false;
        if(isToDelete(root->val, to_delete)){
            if(parent!=nullptr){
                if(rootIsLeft){parent->left=nullptr;}
                else{parent->right=nullptr;}
            }
            delete root;
            root = nullptr;
            addChildren = true;
            addNode = false;
        }
        if(addNode){forest.push_back(root);}
        addNodes(left, root, true, to_delete, forest, addChildren);
        addNodes(right, root, false, to_delete, forest, addChildren);
    }
};
