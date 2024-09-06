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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* tempNew = nullptr;
        unordered_set<int> numSet;
        for(auto x:nums){
            numSet.insert(x);
        }
        while(head!=nullptr){
            if(numSet.find(head->val)==numSet.end()){
                ListNode* newNode = new ListNode(head->val);
                if(newHead==nullptr){
                    newHead = newNode;
                    tempNew = newNode;
                }
                else{
                    tempNew->next = newNode;
                    tempNew = tempNew->next;
                }
            }
            head = head->next;
        }
        return newHead;
    }
};
