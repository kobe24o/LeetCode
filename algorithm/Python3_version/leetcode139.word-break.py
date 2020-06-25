class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False]*(n+1)
        d = set(wordDict)
        dp[0] = True
        for i in range(1,n+1):
            for j in range(i, n+1):
                if s[i-1:j] in d and dp[i-1]:
                    dp[j] = True
        return dp[n]