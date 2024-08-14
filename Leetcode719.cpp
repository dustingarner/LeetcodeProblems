class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[nums.size()-1] - nums[0];
        int goal = 0;
        while(l < r){
            int m = (l+r)/2;
            int count = getPairCount(nums, m);
            if(count < k){
                l = m+1;
            }
            else{
                r = m;
            }
        }
        return l;
    }

    int getPairCount(vector<int>& nums, int maxValue){
        int l = 0, r = nums.size()-1;
        int count = 0;
        while(l<nums.size()-1){
            if(l==r){r++;}
            while(r<nums.size()-1 && nums[r]-nums[l] <= maxValue){
                r++;
            }
            while(nums[r]-nums[l] > maxValue){
                r--;
            }
            count += r-l;
            l++;
        }
        return count;
    }
};  
