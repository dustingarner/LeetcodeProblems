class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height)<2:
            return 0
        total_water = 0
        min_stack = [0]
        current_level = height[0]
        for indi, i in enumerate(height):
            if indi==0:
                continue
            if i<height[min_stack[-1]]:
                min_stack.append(indi)
                current_level = i
                continue
            while(len(min_stack)>0):
                temp_index = min_stack[-1]
                temp_height = height[temp_index]
                water_height = min(temp_height, i) - current_level
                water_width = indi-temp_index-1
                total_water += water_height * water_width
                if i>temp_height:
                    min_stack.pop(-1)
                    current_level = temp_height
                elif i==temp_height:
                    min_stack.pop(-1)
                    min_stack.append(indi)
                    current_level = temp_height
                    break
                else:
                    min_stack.append(indi)
                    break
            
            if len(min_stack)==0:
                min_stack.append(indi)
        return total_water
                
            
