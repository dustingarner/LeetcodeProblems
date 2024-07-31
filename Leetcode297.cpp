/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){return "";}
        string serial;
        int posVal = root->val + 1002;
        char lowDigit = posVal % 64;
        char highDigit = posVal / 64;
        serial.push_back(highDigit);
        serial.push_back(lowDigit);
        string left = serialize(root->left);
        if(left.length()==0){
            serial.push_back(-1);
        }
        else{
            serial += left;
        }
        string right = serialize(root->right);
        if(right.length()==0){
            serial.push_back(-2);
        }
        else{
            serial += right;
        }
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return getDeserial(data, index);
    }

    TreeNode* getDeserial(string& data, int& index){
        if(data==""){
            return nullptr;
        }
        if(data[index]<0){
            index++;
            return nullptr;
        }
        char highDigit = data[index];
        index++;
        char lowDigit = data[index];
        index++;
        int val = (highDigit*64) + lowDigit - 1002;
        TreeNode* node = new TreeNode(val);
        node->left = getDeserial(data, index);
        node->right = getDeserial(data, index);
        return node;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
