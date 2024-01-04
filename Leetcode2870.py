class Solution:
    def minOperations(self, nums: List[int]) -> int:
        num_counts = defaultdict(int)
        for i in nums:
            num_counts[i] += 1
        operations = 0
        for i in list(num_counts.values()):
            if i == 1:
                return -1
            operations += 2 * (i // 6)
            mod_six = i % 6
            if mod_six == 0:
                pass
            elif mod_six < 4:
                operations += 1
            else:
                operations += 2
        return operations
            
            
