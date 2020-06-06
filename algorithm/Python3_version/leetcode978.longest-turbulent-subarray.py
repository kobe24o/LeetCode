class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        n = len(A)
        maxlen = 1
        dp0 = [1]*n
        dp1 = [1]*n
        for i in range(1,n):
            if A[i-1] > A[i]:
                dp0[i] = dp1[i-1]+1
            elif A[i-1] < A[i]:
                dp1[i] = dp0[i-1]+1
            maxlen = max(maxlen, max(dp0[i], dp1[i]))
        return maxlen