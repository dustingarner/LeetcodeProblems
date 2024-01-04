class Solution:
    def wordBreak(self, s: str, wordDict: List[str], cullList: bool = True) -> bool:
        n = len(s)
        dp = [False] * (n+1)
        dp[0] = True
        max_len = 0
        for i in wordDict:
            if len(i) > max_len:
                max_len = len(i)

        for i in range(1, n+1):
            for j in range(i - 1, max(i - max_len - 1, -1), -1):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
                    break
        
        return dp[n]
