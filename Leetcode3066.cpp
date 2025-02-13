class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> minHeap;
        for(auto x:nums){
            minHeap.push(x);
        }
        int numOps = 0;
        while(minHeap.size() > 1){
            if(minHeap.top() >= k){
                return numOps;
            }
            long long int num1 = minHeap.top();
            minHeap.pop();
            long long int num2 = minHeap.top();
            minHeap.pop();
            minHeap.push(min(num1, num2) * 2 + max(num1, num2));
            numOps++;
        }
        return numOps;
    }
};
