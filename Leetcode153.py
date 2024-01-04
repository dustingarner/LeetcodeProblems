class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        while(l < r):
            m = ((r - l) // 2) + l
            if nums[l] < nums[m] and nums[l] < nums[r]:
                return nums[l]
            if nums[r] < nums[l] and nums[r] < nums[m]:
                l = m + 1
            if nums[m] <= nums[l] and nums[m] <= nums[r]:
                r = m
        return nums[l]
