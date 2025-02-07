class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colorCounts;
        vector<int> distinctColors (queries.size(), 0);
        unordered_map<int, int> currentColors;
        for(int i = 0; i < queries.size(); ++i){
            int ball = queries[i][0], color = queries[i][1];
            if(colorCounts.find(color) == colorCounts.end()){
                colorCounts[color] = 0;
            }
            if(currentColors.find(ball) == currentColors.end()){
                currentColors[ball] = -1;
            }
            int prevColor = currentColors[ball];
            currentColors[ball] = color;
            colorCounts[color]++;
            int tempDistinct = i == 0 ? 0 : distinctColors[i-1];
            if(colorCounts[color] == 1){
                tempDistinct++;
            }
            if(prevColor != -1){
                colorCounts[prevColor]--;
                if(colorCounts[prevColor] == 0){
                    tempDistinct--;
                }
            }
            distinctColors[i] = tempDistinct;
        }
        return distinctColors;
    }
};
