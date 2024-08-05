class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> seen;
        for(auto x:arr){
            if(seen.find(x)==seen.end()){
                seen[x] = 0;
            }
            seen[x]++;
        }
        int counter = 0;
        for(auto x:arr){
            if(seen[x]!=1){
                continue;
            }
            counter++;
            if(counter==k){
                return x;
            }
        }
        return "";
    }
};
