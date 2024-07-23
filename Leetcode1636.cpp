class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequencies;
        for(auto x:nums){
            if(frequencies.find(x)==frequencies.end()){
                frequencies[x] = 0;
            }
            frequencies[x]++;
        }
        sort(nums.begin(), nums.end(), [&frequencies](int a, int b){
            if(frequencies[a]==frequencies[b]){return a>b;}
            return frequencies[a]<frequencies[b];});
        return nums;
    }
};
