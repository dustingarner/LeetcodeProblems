class Solution {
public:
    vector<vector<string>> partition(string& s, int index = 0) {
        vector<vector<string>> part;
        if(index==s.length()){
            return part;
        }
        for(int i=index; i<s.length(); ++i){
            if(isOddPal(s, i, index)){
                string tempWord = s.substr(index, ((i-index)*2)+1);
                vector<vector<string>> tempPart = partition(s, (2*i-index+1));
                for(int j=0; j<tempPart.size(); ++j){
                    tempPart[j].insert(tempPart[j].begin(), tempWord);
                }
                part.insert(part.begin(), tempPart.begin(), tempPart.end());
                if(tempPart.size()==0){
                    part.insert(part.begin(), vector<string> (1, tempWord));
                }
            }
            if(isEvenPal(s, i, index)){
                string tempWord = s.substr(index, ((i-index)*2)+2);
                vector<vector<string>> tempPart = partition(s, (2*i-index+2));
                for(int j=0; j<tempPart.size(); ++j){
                    tempPart[j].insert(tempPart[j].begin(), tempWord);
                }
                part.insert(part.begin(), tempPart.begin(), tempPart.end());
                if(tempPart.size()==0){
                    part.insert(part.begin(), vector<string> (1, tempWord));
                }
            }
        }
        return part;
    }

    bool isOddPal(string& s, int index, int startIndex){
        int tempIndex = index;
        for(int i=1; i<=index-startIndex; ++i){
            if(index+i==s.length()){
                return false;
            }
            if(s[index-i]!=s[index+i]){
                return false;
            }
        }
        return true;
    }

    bool isEvenPal(string& s, int index, int startIndex){
        int tempIndex = index;
        for(int i=0; i<=index-startIndex; ++i){
            if(index+1+i==s.length()){
                return false;
            }
            if(s[index-i]!=s[index+1+i]){
                return false;
            }
        }
        return true;
    }
};
