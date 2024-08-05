class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        unsigned int l = 1, r = x;
        while(l<=r){
            unsigned int m = (l+r)/2;
            if(x/m==m){
                return m;
            }
            if(x/m<m){
                r = m-1;
            }
            if(x/m>m){
                l = m+1;
            }
        }
        if(l*l>x){
            return l-1;
        }
        return l;
    }
};
