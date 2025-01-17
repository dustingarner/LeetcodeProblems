class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int val = 0;
        for(int i = 0; i < derived.size() - 1; ++i){
            val ^= derived[i];
        }
        return val ^= derived[derived.size() - 1] == 0;
    }
};
