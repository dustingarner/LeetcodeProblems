class KthLargest {
public:
    int kth = 0;
    vector<int> numbers;

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        numbers = nums;
        sort(numbers.begin(), numbers.end());
    }
    
    int add(int val) {
        if(numbers.size() == 0 || val > numbers[numbers.size()-1]){
            numbers.push_back(val);
            return numbers[numbers.size()-kth];
        }
        int l = 0;
        int r = numbers.size()-1;
        while(l < r){
            int m = (l+r)/2;
            if(numbers[m] >= val){
                r = m;
            }
            else if(numbers[m] < val){
                l = m+1;
            }
        }
        numbers.insert(numbers.begin() + l, val);
        return numbers[numbers.size()-kth];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
