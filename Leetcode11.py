class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        current_max = 0
        while(l < r):
            lower = height[l] if height[l] < height[r] else height[r]
            area = (r-l) * lower
            current_max = area if area > current_max else current_max
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return current_max
        
