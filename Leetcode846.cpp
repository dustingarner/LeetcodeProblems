class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){return false;}
        sort(hand.begin(), hand.end());
        int l = 0, r = 0;
        while(l < hand.size()){
            r = l;
            int prevNumber = hand[r];
            int count = 1;
            r++;
            l++;
            while(count < groupSize && r < hand.size()){
                if(hand[r] == -1){
                    if(l == r){l++;}
                    r++;
                    continue;
                }
                if(hand[r] - prevNumber > 1){
                    return false;
                }
                if(hand[r] == prevNumber){
                    r++;
                    continue;
                }
                prevNumber = hand[r];
                hand[r] = -1;
                if(l == r){l++;}
                r++;
                count++;
            }
            if(count != groupSize){return false;}
        }
        return true;
    }
};
