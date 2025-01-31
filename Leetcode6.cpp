class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string zigS (s.length(), ' ');
        int counter = 0;
        int spacingSize = numRows * 2 - 2;
        for(int i = 0; i < numRows; ++i){
            int extra = 0;
            int hasSpacing = i != 0 && i != numRows-1;
            while(counter < s.length() && i + extra < s.length()){
                zigS[counter] = s[i + extra];
                counter++;
                extra += spacingSize;
                if(counter < s.length() && hasSpacing && extra - i < s.length()){
                    zigS[counter] = s[extra - i];
                    counter++;
                }
            }
        }
        return zigS;
    }
};
