# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = 0
        node = l1
        counter = 0
        while(node):
            num1 += node.val * pow(10, counter)
            counter += 1
            node = node.next
        
        num2 = 0
        node = l2
        counter = 0
        while(node):
            num2 += node.val * pow(10, counter)
            counter += 1
            node = node.next
        
        num = num1 + num2
        if num == 0:
            return ListNode(val = 0)
        l3 = None
        current_node = None
        while(num > 0):
            val = num % 10
            num -= val
            num //= 10
            temp_node = ListNode(val=val)
            if l3 is None:
                l3 = temp_node
                current_node = l3
                continue
            current_node.next = temp_node
            current_node = temp_node
        return l3
