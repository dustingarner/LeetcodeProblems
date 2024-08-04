class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sequence = {nums[0]};
        int maxSeq = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]>sequence[sequence.size()-1]){
                sequence.push_back(nums[i]);
                int seqSize = sequence.size();
                maxSeq = max(maxSeq, seqSize);
                continue;
            }
            int l=0, r=sequence.size()-1;
            int num = nums[i];
            int goalIndex = -1;
            while(l<=r){
                int m = (l+r)/2;
                if(m==0){
                    goalIndex = sequence[0] < num ? 1 : 0;
                    break;
                }
                if(sequence[m] == num){
                    goalIndex = m;
                    break;
                }
                if(sequence[m] >= num && sequence[m-1] < num){
                    goalIndex = m;
                    break;
                }
                else if(sequence[m] >= num){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            if(sequence[goalIndex]==num){
                continue;
            }
            sequence[goalIndex] = num;
        }
        return maxSeq;
    }
};
