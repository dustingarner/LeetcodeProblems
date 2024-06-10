class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> letterCounts (26, 0);
        vector<bool> originallyIn (26, false);
        int totalCount = 0;
        for(auto& x : s1){
            letterCounts[x-'a']++;
            originallyIn[x-'a'] = true;
            totalCount++;
        }
        int l = 0, r = 0;
        while(r < s2.length()){
            int rIndex = s2[r]-'a';
            letterCounts[rIndex]--;
            totalCount--;
            if(!originallyIn[rIndex]){
                r++;
                while(l < r){
                    int lIndex = s2[l]-'a';
                    letterCounts[lIndex]++;
                    totalCount++;
                    l++;
                }
                continue;
            }
            while(letterCounts[rIndex] < 0){
                int lIndex = s2[l]-'a';
                letterCounts[lIndex]++;
                totalCount++;
                l++;
            }
            if(totalCount==0){return true;}
            r++;
        }
        return false;
    }
};
