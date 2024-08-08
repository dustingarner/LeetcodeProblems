class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> spiral;
        spiral.push_back({rStart, cStart});
        int area = rows * cols;
        vector<int> offsetMult = {-1, 1, 1, -1, -1};
        vector<int> tickMult = {1, 0, -1, 0, 1};
        int offset = 1;
        while(spiral.size()<area){
            for(int i=1; i<offsetMult.size(); ++i){
                for(int j=1; j<(offset*2)+1; ++j){
                    int tempRow = rStart + (offset*offsetMult[i-1]) + (j*tickMult[i-1]);
                    int tempCol = cStart + (offset*offsetMult[i]) + (j*tickMult[i]);
                    if(tempRow<0 || tempCol<0 || tempRow>=rows || tempCol>=cols){
                        continue;
                    }
                    spiral.push_back({tempRow, tempCol});
                }
            }
            offset++;
        }
        return spiral;
    }
};
