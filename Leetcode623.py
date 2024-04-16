# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth==1:
            new_node = TreeNode(val=val, left=root)
            return new_node
        
        def insertRow(node, counter):
            if node==None:
                return
            if counter!=depth:
                insertRow(node.left, counter+1)
                insertRow(node.right, counter+1)
                return
            left = node.left
            right = node.right
            node.left = TreeNode(val=val, left=left)
            node.right = TreeNode(val=val, right=right)
        
        insertRow(root, counter=2)

        return root
