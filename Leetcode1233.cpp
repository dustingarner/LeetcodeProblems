class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> seenFolders;
        vector<string> newFolders;
        sort(folder.begin(), folder.end());
        for(auto x:folder){
            for(int i = 1; i <= x.length(); ++i){
                if(i == x.length()){
                    seenFolders.insert(x);
                    newFolders.push_back(x);
                    break;
                }
                if(x[i] == '/'){
                    string currentFolder = x.substr(0, i);
                    if(seenFolders.find(currentFolder) != seenFolders.end()){
                        break;
                    }
                }
            }   
        }
        return newFolders;
    }
};
