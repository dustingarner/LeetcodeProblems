class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> intNums (nums.size(), 0);
        int n = nums[0].length();
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < n; ++j){
                intNums[i] += pow(2, j) * (nums[i][nums.size()-1-j] - '0');
            }
        }
        int foundNum = -1;
        for(int i = 0; i < pow(2, n); ++i){
            bool noneSame = true;
            for(auto x: intNums){
                if(i == x){
                    noneSame = false;
                }
            }
            if(noneSame){
                foundNum = i;
                break;
            }
        }
        string strNum (n, '0');
        for(int i = 0; i < n; ++i){
            strNum[n-1-i] = (foundNum % 2) + '0';
            foundNum /= 2;
        }
        return strNum;
    }
};
