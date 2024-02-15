class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums = sorted(nums)
        total = sum(nums)
        for i in range(len(nums)-1, 0, -1):
            length = nums[i]
            total -= length
            if length<total:
                return length+total
            if i<3:
                break
        return -1
