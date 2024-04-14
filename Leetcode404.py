# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        def addLeftLeaf(node, isLeft):
            if node.left==None and node.right==None and isLeft:
                return node.val
            elif node.left==None and node.right==None:
                return 0

            leftSum = 0
            if node.right != None:
                leftSum += addLeftLeaf(node.right, False)
            if node.left != None:
                leftSum += addLeftLeaf(node.left, True)
            return leftSum
        
        return addLeftLeaf(root, False)

        
