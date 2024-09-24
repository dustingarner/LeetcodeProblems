class Solution {
public:
    void reverseString(string& str){
        int l = 0, r = str.length()-1;
        while(l<r){
            char temp = str[l];
            str[l] = str[r];
            str[r] = temp;
            l++;
            r--;
        }
    }

    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        if(num2.length() > num1.length()){
            swap(num1, num2);
        }
        string product = "";
        reverseString(num1);
        reverseString(num2);
        int remainder = 0;
        int start1 = 0;
        int start2 = 0;
        while(start2<num2.length()){
            int point1 = start1, point2 = start2;
            while(point1>=0 && point2<num2.length()){
                int char1 = num1[point1]-'0', char2 = num2[point2]-'0';
                remainder += char1*char2;
                point1--;
                point2++;
            }
            char tempProduct = (remainder%10)+'0';
            remainder /= 10;
            product.push_back(tempProduct);
            start1++;
            if(start1==num1.length()){
                start1--;
                start2++;
            }
        }
        while(remainder>0){
            char tempProduct = (remainder%10)+'0';
            remainder /= 10;
            product.push_back(tempProduct);
        }
        reverseString(product);
        return product;
    }
};
