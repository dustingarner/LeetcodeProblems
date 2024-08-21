class Solution {
public:
    int jump(vector<int>& nums) {
        vector<pair<int, int>> dists;
        dists.push_back({nums.size()-1, 0});
        for(int i=nums.size()-2; i>=0; --i){
            int currentReach = nums[i]+i;
            if(currentReach<dists[dists.size()-1].first){
                continue;
            }
            while(dists.size()>1 && currentReach>=dists[dists.size()-2].first){
                dists.pop_back();
            }
            dists.push_back({i, dists[dists.size()-1].second+1});
        }
        return dists[dists.size()-1].second;
    }
};
