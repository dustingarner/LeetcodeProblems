# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        starter_head = head
        if head.next is None and n == 0:
            return head
        elif head.next is None and n == 1:
            return None
        n_minus_1th_node = head
        counter = 0
        while(head):
            if counter - n - 1 >= 0:
                n_minus_1th_node = n_minus_1th_node.next
            head = head.next
            counter += 1
        if counter == n:
            nth_node = starter_head
            starter_head = starter_head.next
            nth_node.next = None
            return starter_head
        nth_node = n_minus_1th_node.next
        n_minus_1th_node.next = nth_node.next
        nth_node.next = None
        return starter_head
