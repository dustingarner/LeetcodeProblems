class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        while(l < r):
            m = ((r-l)//2)+l
            print(l, m, r)
            if nums[m] == target:
                return m
            
            if nums[m] < target:
                if nums[r] < target and nums[m] <= nums[r]:
                    r = m
                else:
                    l = m + 1
            else:
                if nums[l] > target and nums[m] >= nums[l]:
                    l = m + 1
                else:
                    r = m

        if nums[l] == target:
            return l
        if nums[r] == target:
            return r
        return -1
