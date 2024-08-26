class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> letterCounts (26, 0);
        int maxValue = 0;
        int maxCount = 0;
        for(auto x:tasks){
            int index = x-'A';
            letterCounts[index]++;
            if(letterCounts[index]>maxValue){
                maxValue = letterCounts[index];
                maxCount = 1;
            }
            else if(letterCounts[index]==maxValue){
                maxCount++;
            }
        }
        return max((int)tasks.size(), (maxValue-1)*(n+1)+maxCount);
    }
};
