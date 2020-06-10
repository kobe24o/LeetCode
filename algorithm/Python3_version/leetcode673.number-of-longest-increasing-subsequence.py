class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        maxlen = 1
        dp = [1]*n
        count = [1]*n
        for i in range(1,n):
            for j in range(i):
                if nums[i] > nums[j]:
                    if dp[j]+1 > dp[i]:
                        dp[i] = dp[j]+1
                        count[i] = count[j]
                    elif dp[j]+1 == dp[i]:
                        count[i] += count[j]
            maxlen = max(maxlen, dp[i])
        ans = 0
        for i in range(n):
            if dp[i]==maxlen:
                ans += count[i]
        return ans