class Solution(object):
    def maxSubArray(self, nums):
        most_neg = 0
        most_pos = nums[0]
        current_neg = 0
        current_pos = 0
        for indi, i in enumerate(nums):
            if indi != 0:
                current_neg += nums[indi - 1]
            if most_neg > current_neg:
                most_neg = current_neg
            current_pos += i
            if current_pos - most_neg > most_pos:
                most_pos = current_pos - most_neg
        return most_pos
