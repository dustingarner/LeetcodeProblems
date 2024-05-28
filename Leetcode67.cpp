class Solution {
public:
    string addBinary(string a, string b) {
        string value = "";
        int indA = a.length()-1;
        int indB = b.length()-1;
        int carryOver = 0;
        while(indA >= 0 || indB >= 0 || carryOver > 0){
            int valA = indA < 0 ? '0' : a[indA];
            int valB = indB < 0 ? '0' : b[indB];
            carryOver += (valA=='0' && valB=='0') ? 0 : ((valA=='0'||valB=='0') ? 1 : 2);
            string nextChar = (carryOver%2 == 1) ? "1" : "0";
            value.insert(0, nextChar);
            carryOver >>= 1;
            indA--;
            indB--;
        }
        return value;
    }
};
