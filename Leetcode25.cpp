/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        ListNode* currentNode = head;
        ListNode* prevNode = nullptr;
        while(currentNode!=nullptr){
            ListNode* reversedNode = reverseGroup(currentNode, k);
            currentNode = reversedNode;
            if(currentNode==nullptr){break;}
            if(prevNode==nullptr){
                head = currentNode;
            }
            else{
                prevNode->next = currentNode;
            }
            for(int i=0; i<k; ++i){
                if(currentNode==nullptr){break;}
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        return head;
    }

    ListNode* reverseGroup(ListNode* start, int k){
        if(start==nullptr){return nullptr;}
        ListNode* currentNode = start;
        ListNode* lastNode = currentNode;
        for(int i=0; i<k; ++i){
            if(currentNode==nullptr){
                return nullptr;
            }
            lastNode = currentNode;
            currentNode = currentNode->next;
        }
        currentNode = start;
        for(int i=0; i<k-1; ++i){
            ListNode* tempNext = currentNode->next;
            currentNode->next = lastNode->next;
            lastNode->next = currentNode;
            currentNode = tempNext;
        }
        return currentNode;
    }
};
