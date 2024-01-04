# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head.next is None:
            return
        current = head
        length = 0
        while(current):
            current = current.next
            length += 1
        counter = 0
        end = ((length + 1) // 2) - 1
        tail = head
        while(counter < end):
            tail = tail.next
            counter += 1
        next_node = tail.next
        tail.next = None
        tail = next_node
        prev_node = None
        while(tail):
            next_node = tail.next
            tail.next = prev_node
            prev_node = tail
            tail = next_node
        tail = prev_node
        while(True):
            next_head = head.next
            head.next = tail
            if tail.next is None:
                tail.next = next_head
                break
            next_tail = tail.next
            tail.next = next_head
            head = next_head
            tail = next_tail
