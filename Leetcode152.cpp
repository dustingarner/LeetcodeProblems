class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double head = 1, tail = 1;
        double product = INT_MIN;
        for(int i=0; i<nums.size(); ++i){
            if(head==0){
                head = 1;
            }
            if(tail==0){
                tail = 1;
            }
            head *= nums[i];
            tail *= nums[nums.size()-1-i];
            product = max(head, product);
            product = max(tail, product);
        }
        return product;
    }
};
