class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if not len(s) == len(t):
            return False
        charDict = {}
        for i,j in zip(s, t):
            if not i in charDict:
                charDict[i] = 1
            else:
                charDict[i] += 1
            if not j in charDict:
                charDict[j] = -1
            else:
                charDict[j] -= 1
        for i in charDict.keys():
            if charDict[i] != 0:
                return False
        return True
