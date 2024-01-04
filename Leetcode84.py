class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = heights[0]
        if len(heights) == 0:
            return max_area
        height_stack = []
        index_stack = []
        last_zero = -1
        for indi, i in enumerate(heights):
            if indi == 0:
                height_stack.append(i)
                index_stack.append(indi)
                continue
            
            add_final = False
            while(len(height_stack) > 0 and height_stack[-1] > i):
                add_final = True
                area = (indi - index_stack[-1]) * height_stack[-1]
                max_area = area if area > max_area else max_area
                height_stack.pop()
                last_index = index_stack.pop()
            if add_final:
                height_stack.append(i)
                index_stack.append(last_index)                
            if i > height_stack[-1]:
                height_stack.append(i)
                index_stack.append(indi)
        while(len(height_stack) > 0):
            area = (len(heights) - index_stack[-1]) * height_stack[-1]
            max_area = area if area > max_area else max_area
            height_stack.pop()
            index_stack.pop()
        return max_area
            
