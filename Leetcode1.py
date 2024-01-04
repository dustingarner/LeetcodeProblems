class Solution(object):
    def twoSum(self, nums, target):
        seen_nums = {}
        for indi, i in enumerate(nums):
            goal = target - i
            if goal in seen_nums:
                return [seen_nums[goal], indi]
            else:
                seen_nums[i] = indi
        return [0,0]
