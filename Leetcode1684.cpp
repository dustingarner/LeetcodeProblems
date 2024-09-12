class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> included;
        for(auto x:allowed){
            included.insert(x);
        }
        int numberConsistent = 0;
        for(auto x:words){
            bool consistent = true;
            for(auto y:x){
                if(included.find(y)==included.end()){
                    consistent = false;
                    break;
                }
            }
            numberConsistent += consistent;
        }
        return numberConsistent;
    }
};
