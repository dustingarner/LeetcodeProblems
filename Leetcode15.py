class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        tested = False
        current_num = nums[0]
        triplets = []
        for i in range(len(nums) - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l, r = i + 1, len(nums) - 1
            while(l < r):
                total = nums[i] + nums[l] + nums[r]
                if total < 0:
                    l += 1
                elif total > 0:
                    r -= 1
                else:
                    triplet = [nums[i], nums[l], nums[r]]
                    triplets.append(triplet)
                    while(l < r and nums[l] == triplet[1]):
                        l += 1
                    while(l < r and nums[r] == triplet[2]):
                        r -= 1
        return triplets
            
