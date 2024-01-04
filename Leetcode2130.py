# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow = fast = head
        prev = None

        while fast and fast.next:
            fast = fast.next.next
            temp = slow.next
            prev, prev.next = slow, prev
            slow = temp
        
        maxSum = 0
        while slow:
            maxSum = max(maxSum, slow.val + prev.val)
            slow = slow.next
            prev = prev.next
        return maxSum
