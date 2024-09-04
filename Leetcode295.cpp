class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> higherHalf;
    priority_queue<int> lowerHalf;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(higherHalf.empty()){
            higherHalf.push(num);
            return;
        }
        if(num>=higherHalf.top()){
            higherHalf.push(num);
        }
        else{
            lowerHalf.push(num);
        }
        while(higherHalf.size()>lowerHalf.size()+1){
            int top = higherHalf.top();
            higherHalf.pop();
            lowerHalf.push(top);
        }
        while(lowerHalf.size()>higherHalf.size()){
            int top = lowerHalf.top();
            lowerHalf.pop();
            higherHalf.push(top);
        }
    }
    
    double findMedian() {
        if(higherHalf.size()>lowerHalf.size()){
            return (double)higherHalf.top();
        }
        else{
            return ((double)higherHalf.top()+(double)lowerHalf.top())/2.0;
        }
    }
};
