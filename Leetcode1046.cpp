class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1){
            return stones[0];
        }
        for(int i=0; i<stones.size(); ++i){
            heapifyUp(stones, i);
        }
        if(stones.size()==2){
            return stones[0]-stones[1];
        }
        while(stones[1]!=0 || stones[2]!=0){
            int maxInd = stones[1] >= stones[2] ? 1 : 2;
            stones[0] -= stones[maxInd];
            stones[maxInd] = 0;
            heapifyDown(stones, maxInd);
            heapifyDown(stones, 0);
        }
        return stones[0];
    }

    void heapifyUp(vector<int>& stones, int index){
        if(index==0){
            return;
        }
        int parentIndex = (index-1)/2;
        if(stones[parentIndex]>=stones[index]){
            return;
        }
        int temp = stones[parentIndex];
        stones[parentIndex] = stones[index];
        stones[index] = temp;
        heapifyUp(stones, parentIndex);
    }

    void heapifyDown(vector<int>& stones, int index){
        int leftIndex = index*2+1;
        int rightIndex = leftIndex+1;
        int left = leftIndex >= stones.size() ? 0 : stones[leftIndex];
        int right = rightIndex >= stones.size() ? 0 : stones[rightIndex];
        if(stones[index]>=left && stones[index]>=right){
            return;
        }
        int higherIndex = left >= right ? leftIndex : rightIndex;
        int temp = stones[higherIndex];
        stones[higherIndex] = stones[index];
        stones[index] = temp;
        heapifyDown(stones, higherIndex);
    }
};
