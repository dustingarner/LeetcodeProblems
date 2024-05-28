class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0;
        int maxLength = 0;
        int currentCost = maxCost;
        while(l < s.length()){
            while(currentCost >= 0){
                maxLength = max(r-l, maxLength);
                if(r >= s.length()){
                    break;
                }
                currentCost -= abs(s[r] - t[r]);
                r++;
            }
            currentCost += abs(s[l] - t[l]);
            l++;
        }
        return maxLength;
    }
};
