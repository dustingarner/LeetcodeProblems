# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        letters = {x: y for x, y in zip(range(26), "abcdefghijklmnopqrstuvwxyz")}

        def findSmallest(node, parent_val = None):
            if node.left==None and node.right==None:
                return [node.val]
            
            elif node.left==None:
                return findSmallest(node.right, node.val) + [node.val]
            elif node.right==None:
                return findSmallest(node.left, node.val) + [node.val]

            left = findSmallest(node.left, node.val) + [node.val]
            right = findSmallest(node.right, node.val) + [node.val]
            print(left, right)
            min_length = min(len(left), len(right)) + 1
            for l, r in zip((left+[parent_val])[:min_length], 
                            (right+[parent_val])[:min_length]):
                if l==None or r==None:
                    break
                if l>r:
                    return right
                if r>l:
                    return left
            
            if len(right)>len(left):
                return left
            else:
                return right
        smallest = findSmallest(root)
        return "".join([letters[x] for x in smallest])
