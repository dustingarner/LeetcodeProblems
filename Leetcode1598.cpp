class Solution {
public:
    int minOperations(vector<string>& logs) {
        int layers = 0;
        for(auto x : logs){
            if(x == "../" && layers == 0){
                continue;
            }
            else if(x == "../"){
                layers--;
            }
            else if(x == "./"){
                continue;
            }
            else{
                layers++;
            }
        }
        return layers;
    }
};
