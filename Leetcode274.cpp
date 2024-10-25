class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int maxH = 0;
        for(int i = citations.size()-1; i >= 0; --i){
            maxH = max(maxH, min((int)citations.size()-i, citations[i]));
        }
        return maxH;
    }
};
