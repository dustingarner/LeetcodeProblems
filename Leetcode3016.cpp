class Solution {
public:
    static bool comp(int a, int b){
        return b < a;
    }

    int minimumPushes(string word) {
        int letterFreq[26] = {0};
        for(auto x:word){
            letterFreq[x-'a']++;
        }
        sort(begin(letterFreq), end(letterFreq), comp);
        int pushCount = 0;
        for(int i=0; i<26; ++i){
            int presses = (i/8)+1;
            pushCount += letterFreq[i] * presses;
        }
        return pushCount;
    }
};
