class Solution {
public:
    class LinkedNode {
        public:
        int val;
        LinkedNode* next = nullptr;
        LinkedNode* prev = nullptr;
    };

    class LinkedList {
        public:
        LinkedNode* head = nullptr;
        LinkedNode* tail = nullptr;

        ~LinkedList(){
            deleteAll();
        }

        void deleteFirst(){
            LinkedNode* nextHead = head->next;
            if(nextHead != nullptr){
                nextHead->prev = nullptr;
            }
            delete head;
            head = nextHead;
            if(head == nullptr){tail = nullptr;}
        }

        void deleteLast(){
            LinkedNode* nextTail = tail->prev;
            if(nextTail != nullptr){
                nextTail->next = nullptr;
            }
            delete tail;
            tail = nextTail;
            if(tail == nullptr){head = nullptr;}
        }

        void deleteAll(){
            while(head != nullptr){
                deleteLast();
            }
        }

        void insertLast(int val){
            LinkedNode* newTail = new LinkedNode();
            newTail->val = val;
            newTail->prev = tail;
            if(tail == nullptr){
                head = newTail;
                tail = newTail;
                return;
            }
            tail->next = newTail;
            tail = newTail;
        }

        int getFirst(){
            if(head == nullptr){return -1;}
            return head->val;
        }

        int getLast(){
            if(tail == nullptr){return -1;}
            return tail->val;
        }

        void print(){
            LinkedNode* currentNode = head;
            if(head == nullptr){cout << "List is empty." << endl;}
            while(currentNode != nullptr){
                cout << currentNode->val << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxValues;
        LinkedList localMaxStack = LinkedList();
        localMaxStack.insertLast(0);
        for(int i = 1; i < k; ++i){
            int currentVal = nums[i];
            while(localMaxStack.getLast() != -1 && 
                    nums[localMaxStack.getLast()] <= currentVal){
                localMaxStack.deleteLast();
            }
            localMaxStack.insertLast(i);
        }
        maxValues.push_back(nums[localMaxStack.getFirst()]);
        for(int i = 1; i < nums.size()-k+1; ++i){
            int newInd = i+k-1;
            if(localMaxStack.getFirst() == i-1){
                localMaxStack.deleteFirst();
            }
            while(localMaxStack.getLast() != -1 && 
                    nums[localMaxStack.getLast()] <= nums[newInd]){
                localMaxStack.deleteLast();
            }
            localMaxStack.insertLast(newInd);
            maxValues.push_back(nums[localMaxStack.getFirst()]);
        }
        return maxValues;
    }
};
