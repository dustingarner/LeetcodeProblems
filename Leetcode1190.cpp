class Solution {
public:
    string reverseParentheses(string s) {
        findAndReverse(s, 0, s.length()-1);
        for(int i = s.length()-1; i >= 0; --i){
            if(s[i] == '(' || s[i] == ')'){
                s.erase(i, 1);
            }
        }
        return s;
    }

    void findAndReverse(string& s, int start, int end){
        if(start >= end){return;}
        int layer = 0;
        int startInd = -1, endInd = -1;
        for(int i = start; i <= end; ++i){
            if(s[i] == '('){
                if(layer == 0){
                    startInd = i;
                }
                layer++;
            }
            if(s[i] == ')'){
                layer--;
                if(layer == 0){
                    endInd = i;
                }
            }
            if(startInd != -1 && endInd != -1){
                findAndReverse(s, startInd+1, endInd-1);
                reverse(s, startInd+1, endInd-1);
                startInd = -1;
                endInd = -1;
            }
        }
    }

    void reverse(string& s, int start, int end){
        while(start <= end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};
