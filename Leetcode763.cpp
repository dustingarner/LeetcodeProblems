class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> endInds (26, 0);
        for(int i=0; i<s.length(); ++i){
            endInds[s[i]-'a'] = i;
        }
        int currentStart = 0, currentEnd = 0;
        vector<int> partitions;
        for(int i=0; i<s.length(); ++i){
            if(i>currentEnd){
                partitions.push_back(currentEnd-currentStart+1);
                currentStart = i;
                currentEnd = i;
            }
            currentEnd = max(currentEnd, endInds[s[i]-'a']);
        }
        partitions.push_back(currentEnd-currentStart+1);
        return partitions;
    }
};
