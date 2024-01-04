"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None
        list1 = head
        list2 = Node(head.val, next = None, random = None)
        head2 = list2
        counter = 0
        while(True):
            list1.val = counter
            if list1.next is None:
                break
            list1 = list1.next
            list2.next = Node(list1.val, next = None, random = None)
            list2 = list2.next
            counter += 1
        list1 = head
        list2 = head2
        while(list2):
            random = list1.random
            if random is None:
                list1 = list1.next
                list2 = list2.next
                continue
            random_val = random.val
            counter = 0
            rand_head = head2
            while(counter < random_val):
                rand_head = rand_head.next
                counter += 1
            list2.random = rand_head
            list1 = list1.next
            list2 = list2.next
        list1 = head
        list2 = head2
        while(list1):
            list1.val = list2.val
            list1 = list1.next
            list2 = list2.next
        return head2

            
