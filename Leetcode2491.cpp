class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int l = 0, r = skill.size()-1;
        int sum = skill[l] + skill[r];
        long long totalSum = 0;
        while(l < r){
            if(skill[l] + skill[r] != sum){
                return -1;
            }
            totalSum += skill[l] * skill[r];
            l++;
            r--;
        }
        return totalSum;
    }
};
