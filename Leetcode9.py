class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        numStr = str(x)
        for i in range(len(numStr) // 2):
            if numStr[i] != numStr[-i - 1]:
                return False
        return True
