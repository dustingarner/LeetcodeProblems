class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return 1
        nums = sorted(nums)
        prev_num = nums[0]
        counter = 1
        largest_counter = 1
        for indi, i in enumerate(nums):
            if indi == 0:
                continue
            if prev_num == i - 1:
                counter += 1
            elif prev_num == i:
                continue
            else:
                counter = 1
            if largest_counter < counter:
                largest_counter = counter
            prev_num = i
        return largest_counter
