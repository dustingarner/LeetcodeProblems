class Solution {
public:
    int numDecodings(string s) {
        vector<int> count (s.length()+1, 0);
        count[s.length()] = 1;
        for(int i=s.length()-1; i>=0; --i){
            if(s[i]=='0' && (i==0 || !(s[i-1]=='1' || s[i-1]=='2'))){
                return 0;
            }
            if(i==s.length()-1){
                count[i] = 1;
                continue;
            }
            if(s[i]=='1'){
                count[i] = count[i+1];
                if(s[i+1]!='0' && (i==s.length()-2 || s[i+2]!='0')){
                    count[i] += count[i+2];
                }
            }
            else if(s[i]=='2'){
                count[i] = count[i+1];
                if(s[i+1]!='0' && s[i+1]-'0'<7 && (i==s.length()-2 || s[i+2]!='0')){
                    count[i] += count[i+2];
                }
            }
            else{
                count[i] = count[i+1];
            }
        }
        return count[0];
    }
};
