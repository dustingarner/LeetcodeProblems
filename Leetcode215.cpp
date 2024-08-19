class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        for(auto x:nums){
            heap.push_back(x);
            heapifyUp(heap, heap.size()-1);
        }
        int counter = 1;
        while(counter<k){
            heap[0] = heap[heap.size()-1];
            heap.pop_back();
            heapifyDown(heap, 0);
            counter++;
        }
        return heap[0];
    }

    void heapifyUp(vector<int>& heap, int index){
        if(index==0){
            return;
        }
        int parent = (index-1)/2;
        if(heap[parent]>heap[index]){
            return;
        }
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        heapifyUp(heap, parent);
    }

    void heapifyDown(vector<int>& heap, int index){
        int right = (index+1)*2;
        int left = right-1;
        int child;
        if(left>=heap.size()){
            return;
        }
        if(right>=heap.size()){
            child = left;
        }
        else{
            child = heap[left]>heap[right] ? left : right;
        }
        if(heap[index]>heap[child]){
            return;
        }
        int temp = heap[index];
        heap[index] = heap[child];
        heap[child] = temp;
        heapifyDown(heap, child);
    }
};
