class Solution:
    def minimumPossibleSum(self, n: int, target: int) -> int:
        beaut_count = 0
        for i in range(1, n+1):
            beaut_count += i
        first_higher = math.floor(target / 2) + 1
        num_sums = 0
        for i in range(first_higher, n + 1):
            if i == target:
                break
            num_sums += 1
        addend = n - first_higher + 1
        if first_higher + addend < target:
            addend = target - first_higher
        print(num_sums, first_higher, addend)
        for i in range(num_sums):
            beaut_count += addend
        return beaut_count
        
