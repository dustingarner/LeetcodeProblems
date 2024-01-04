from math import ceil
from math import floor

class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        lowestSum = 0
        for i in range(1, n + 1):
            lowestSum += i
        numberSums = ceil(k / 2) - 1
        
        firstAddend = floor(k / 2) + 1
        numberAvoided = 0
        for i in range(numberSums):
            if firstAddend + i > n:
                numberAvoided = numberSums - i
                numberSums = i
                break
        
        addition = n - floor(k / 2) + numberAvoided      
        lowestSum += addition * numberSums
        return lowestSum
