class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        int counter = 0;
        while(counter < 32){
            reversed += n % 2;
            if(counter==31){break;}
            reversed <<= 1;
            n >>= 1;
            counter++;
        }
        return reversed;
    }
};
