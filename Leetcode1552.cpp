class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position[position.size()-1]-position[0];
        int mid = (high + low) / 2;
        int highestPossible = 1;
        while(high >= low){
            mid = (high + low) / 2;
            int count = m-1;
            int prev = position[0];
            int isPossible = false;
            for(int i = 1; i < position.size(); ++i){
                if(position[i] - prev < mid){
                    continue;
                }
                prev = position[i];
                count--;
                if(count == 0){
                    isPossible = true;
                    break;
                }
            }
            if(isPossible){
                highestPossible = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return highestPossible;
    }
};
