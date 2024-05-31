class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int endXor = 0;
        for(auto x : nums){
            endXor ^= x;
        }
        int mismatch = 1;
        int bitTest = endXor & mismatch;
        cout << endXor << endl;
        while(bitTest == 0){
            if(mismatch == pow(2, 30)){
                mismatch *= -2;
            }
            else{
                mismatch *= 2;
            }
            bitTest = endXor & mismatch;
        }
        int numOn = 0, numOff = 0;
        for(auto x : nums){
            bitTest = x & mismatch;
            if(bitTest == 0){
                numOff ^= x;
            }
            else{
                numOn ^= x;
            }
        }
        vector<int> numbers {numOff, numOn};
        return numbers;
    }
};
