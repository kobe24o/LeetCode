class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        n = len(stones)
        s = sum(stones)
        dp = [False]*(s//2+1)
        dp[0] = True
        for i in range(n):
            for j in range(s//2,-1,-1):
                if dp[j] and j+stones[i] <= s//2:
                    dp[j+stones[i]] = True
        j = s//2
        while not dp[j]:
            j -= 1
        return s-2*j