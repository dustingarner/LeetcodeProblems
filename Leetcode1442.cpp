class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int totalTriplets = 0;
        for(int i = 0; i < arr.size()-1; i++){
            int currentXor = arr[i];
            for(int j = i+1; j < arr.size(); j++){
                currentXor = currentXor ^ arr[j];
                if(currentXor == 0){
                    totalTriplets += j-i;
                }
            }
        }
        return totalTriplets;
    }
};
