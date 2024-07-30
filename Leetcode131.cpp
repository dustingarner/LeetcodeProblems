class Solution {
public:
    vector<vector<string>> partition(string& s, int index = 0) {
        vector<vector<string>> part;
        vector<string> palindromes;
        backtrack(part, palindromes, s, 0, 1);
        return part;
    }

    void backtrack(vector<vector<string>>& part, vector<string>& palindromes, string& s, int start, int length){
        if(start==s.length()){
            part.push_back(palindromes);
            return;
        }
        if(start+length-1==s.length()){
            return;
        }
        backtrack(part, palindromes, s, start, length+1);
        if(isPalindrome(start, length, s)){
            palindromes.push_back(s.substr(start, length));
            backtrack(part, palindromes, s, start+length, 1);
            palindromes.pop_back();
        }
    }

    bool isPalindrome(int start, int length, string& s){
        if(start+length-1 == s.length()){
            return false;
        }
        int end = start+length-1;
        while(start < end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
