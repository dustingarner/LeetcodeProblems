class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        even_counter = 0
        for i in nums:
            if i % 2 == 0:
                even_counter += 1
            if even_counter >= 2:
                return True
        return False
        
