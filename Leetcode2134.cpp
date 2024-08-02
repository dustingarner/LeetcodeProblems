class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int oneCount = 0;
        int firstOne = -1;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==1){
                oneCount++;
                firstOne = firstOne==-1 ? i : firstOne;
            }
        }
        if(firstOne==-1){
            return 0;
        }
        int minimum = INT_MAX;
        int left = firstOne, right = firstOne;
        int zeroCount = 0;
        int windowOneCount = 1;
        do{ 
            do{
                minimum = min(minimum, oneCount-windowOneCount);
                right = right==nums.size()-1 ? 0 : right+1;
                if(nums[right]==0){
                    zeroCount++;
                }
                else{
                    windowOneCount++;
                }
            } while(right!=left && zeroCount <= oneCount-windowOneCount);

            while(zeroCount > oneCount-windowOneCount){
                if(nums[left]==0){
                    zeroCount--;
                }
                else{
                    windowOneCount--;
                }
                left = left==nums.size()-1 ? 0 : left+1;
                if(left==right || left==firstOne){
                    break;
                }
            }
        }while(left!=firstOne);
        if(minimum==INT_MAX){
            return 0;
        }
        return minimum;
    }
};
