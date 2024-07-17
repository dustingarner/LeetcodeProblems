class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.length(); ++i){
            int left, right;
            for(int j=i; j<i+2; ++j){
                left = i;
                right = j;
                while(left>=0 && right<s.length() && s[left]==s[right]){
                    count++;
                    left--;
                    right++;
                }
            }
        }
        return count;
    }
};
