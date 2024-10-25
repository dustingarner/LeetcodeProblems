class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start=0, int end=INT_MAX) {
        if(end < start){
            return nullptr;
        }
        end = end == INT_MAX ? nums.size()-1 : end;
        int middle = (start+end) / 2;
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = sortedArrayToBST(nums, start, middle-1);
        node->right = sortedArrayToBST(nums, middle+1, end);
        return node;
    }
};
