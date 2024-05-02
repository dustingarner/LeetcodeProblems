class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        max_value = 0
        nums_found = {}
        for i in nums:
            nums_found[i] = False
        for i in nums:
            is_pos = True if i>0 else False
            nums_found[i] = True
            if not i*-1 in nums_found:
                continue
            if nums_found[i*-1]:
                max_value = max(max_value, abs(i))
        if max_value==0:
            return -1
        return max_value
