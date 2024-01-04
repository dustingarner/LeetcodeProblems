# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2
        elif list2 is None:
            return list1
        if list1.val < list2.val:
            head, main, other = list1, list1, list2
        else:
            head, main, other = list2, list2, list1
        while(main):
            main_next = main.next
            if main_next is None:
                main.next = other
                break
            if other is None:
                break
            if main_next.val <= other.val:
                main = main_next
                continue
            main.next = other
            while(other):
                main = other
                other = other.next
                if other is None:
                    break
                if other.val >= main_next.val:
                    break
            main.next = main_next
            main = main.next
        return head
