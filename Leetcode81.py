class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l = 0
        r = len(nums) - 1
        while(l < r):
            m = ((r-l)//2) + l
            if nums[m] == target:
                return True

            if nums[l] == nums[m] and nums[m] == nums[r]:
                right_higher = sum(nums[l:(m + 1)]) < sum(nums[m:r + 1])
                if nums[m] < target and right_higher:
                    l = m + 1
                elif nums[m] < target:
                    r = m
                elif nums[m] > target and right_higher:
                    r = m
                else:
                    l = m + 1
                continue
                

            if nums[m] < target and nums[r] < target and \
                    nums[m] <= nums[r]:
                r = m
            elif nums[m] < target:
                l = m + 1
            elif nums[m] > target and nums[l] > target and \
                    nums[m] >= nums[l]:
                l = m + 1
            else:
                r = m

        if nums[l] == target:
            return True
        return False
