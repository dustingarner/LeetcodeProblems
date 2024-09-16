class Solution {
public:
    int convertToMin(string time){
        return (time[4]-'0') + (time[3]-'0')*10 + (time[1]-'0')*60 + (time[0]-'0')*600;
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end(), [this](string a, string b){
            return this->convertToMin(b) > this->convertToMin(a);
        });
        int minDif = INT_MAX;
        for(int i=0; i<timePoints.size(); ++i){
            int nextInd = i==timePoints.size()-1 ? 0 : i+1;
            int current = convertToMin(timePoints[i]);
            int next = convertToMin(timePoints[nextInd]);
            if(nextInd==0){
                next += (60*24);
            }
            minDif = min(minDif, next-current);
        }
        return minDif;
    }
};
