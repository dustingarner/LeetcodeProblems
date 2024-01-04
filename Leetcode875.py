class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)

        while(l < r):
            m = (l+r)//2
            total_hours = 0
            for i in piles:
                total_hours += math.ceil(i/m)
            if total_hours > h:
                l = m + 1
            else:
                r = m
        return l
