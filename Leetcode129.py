# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:

        def findRootSum(node, currentSum):
            currentSum *= 10
            currentSum += node.val
            if node.left==None and node.right==None:
                return currentSum
            total = 0
            if node.left!=None:
                total += findRootSum(node.left, currentSum)
            if node.right!=None:
                total += findRootSum(node.right, currentSum)
            return total
        
        return findRootSum(root, 0)
