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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int index = 1;
        int firstCritical = -1;
        int prevCritical = -1;
        int minDist = INT_MAX;
        int prevValue = head->val;
        head = head->next;
        while(head->next != nullptr){
            if((prevValue < head->val && head->next->val < head->val) ||
                    (prevValue > head->val && head->next->val > head->val)){
                if(firstCritical == -1){
                    firstCritical = index;
                    prevCritical = index;
                }
                else{
                    minDist = min(minDist, index - prevCritical);
                    prevCritical = index;
                }
            }
            prevValue = head->val;
            head = head->next;
            index++;
        }
        int maxDist = -1;
        if(minDist == INT_MAX){
            minDist = -1;
        }
        if(firstCritical != prevCritical){
            maxDist = prevCritical-firstCritical;
        }
        return vector<int> {minDist, maxDist};
    }
};
