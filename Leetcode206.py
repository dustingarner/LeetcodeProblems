# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
        prev_node = None
        current_node = head
        while(True):
            next_node = current_node.next
            current_node.next = prev_node
            if next_node == None:
                break
            prev_node = current_node
            current_node = next_node
        return current_node
        
