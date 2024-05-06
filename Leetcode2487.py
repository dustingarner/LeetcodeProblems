# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None
        head.next = self.removeNodes(head.next)
        if head.next == None:
            return head
        if head.val < head.next.val:
            next_node = head.next
            del head
            return next_node
        return head
