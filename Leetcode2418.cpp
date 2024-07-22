class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> both;
        for(int i=0; i<names.size(); ++i){
            both.push_back(make_pair(heights[i], names[i]));
        }
        sort(both.begin(), both.end(), [](pair<int, string>& i, pair<int, string>& j){return i.first>j.first;});
        for(int i=0; i<names.size(); ++i){
            names[i] = both[i].second;
        }
        return names;
    }
};
