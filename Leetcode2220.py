class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        counter = 0
        while(start or goal):
            if start%2 != goal%2:
                counter += 1
            start//=2
            goal//=2
        return counter
