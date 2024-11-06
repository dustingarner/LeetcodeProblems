class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode* slow = head->next;
        if(slow == nullptr){
            return false;
        }
        ListNode* fast = head->next->next;
        if(fast == nullptr){
            return false;
        }
        while(fast != nullptr){
            if(slow == fast){
                return true;
            }
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr){
                return false;
            }
            fast = fast->next;
        }
        return false;
    }
};
