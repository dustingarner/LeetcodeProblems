class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        numCount = {}
        for i in nums:
            if not i in numCount:
                numCount[i] = 1
            else:
                numCount[i] += 1
        numCount = sorted(numCount.items(), key = lambda x : x[1], reverse = True)
        mostFreq = []
        for i in range(k):
            mostFreq += [numCount[i][0]]
        return mostFreq

                
