class Solution {
public:
    bool checkValidString(string s) {
        int openMin = 0, openMax = 0;
        for(int i=0; i<s.length(); ++i){
            if(s[i]=='('){
                openMin++;
                openMax++;
            }
            else if(s[i]==')'){
                openMin--;
                openMax--;
            }
            else{
                openMin--;
                openMax++;
            }
            if(openMax < 0){
                return false;
            }
            openMin = max(0, openMin);
        }
        return openMin==0;
    }
};
