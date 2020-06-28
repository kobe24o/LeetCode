class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        minlen = float('inf')
        l, r, ans = 0, 0, 0
        for r in range(len(nums)):
            ans += nums[r]
            while ans >= s:
                minlen = min(minlen, r-l+1)
                ans -= nums[l]
                l += 1
        return minlen if minlen!=float('inf') else 0