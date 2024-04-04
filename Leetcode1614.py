class Solution:
    def maxDepth(self, s: str) -> int:
        current_depth = 0
        max_depth = 0
        for i in s:
            if i=='(':
                current_depth+=1
            elif i==')':
                current_depth-=1
            max_depth = max(max_depth, current_depth)
        return max_depth
