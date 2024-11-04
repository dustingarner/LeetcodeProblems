class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        char currentChar = word[0];
        int repeats = 1;
        for(int i = 1; i < word.length(); ++i){
            if(word[i] != currentChar || repeats == 9){
                comp.push_back(repeats + '0');
                comp.push_back(currentChar);
                currentChar = word[i];
                repeats = 0;
            }
            repeats++;
        }
        comp.push_back(repeats + '0');
        comp.push_back(currentChar);
        return comp;
    }
};
