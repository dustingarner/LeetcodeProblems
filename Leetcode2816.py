# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverseList(head):
            prev = None
            while(head != None):
                next = head.next
                head.next = prev
                prev = head
                head = next
            return prev
        head = reverseList(head)
        original_head = head
        carry_over = 0
        while(head != None):
            doubled = head.val * 2 + carry_over
            carry_over = doubled // 10
            doubled = doubled % 10
            head.val = doubled
            prev = head
            head = head.next
        head = prev
        while(carry_over > 0):
            value = carry_over % 10
            carry_over = carry_over // 10
            head.next = ListNode(value)
            head = head.next
        return reverseList(original_head)
        
