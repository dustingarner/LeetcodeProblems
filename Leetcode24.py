# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        elif head.next is None:
            return head
        firstNode = head
        secondNode = head.next
        head = secondNode
        prevNode = None
        addPrev = False
        while(True):
            secondNode.next, firstNode.next = firstNode, secondNode.next
            if addPrev:
                prevNode.next = secondNode
            if firstNode.next is None or firstNode.next.next is None:
                break
            prevNode = firstNode
            firstNode, secondNode = firstNode.next, firstNode.next.next
            addPrev = True
        return head
