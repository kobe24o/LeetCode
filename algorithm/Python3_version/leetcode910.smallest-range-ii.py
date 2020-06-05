class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        A.sort()
        mindis = float("inf")
        n = len(A)
        for i in range(n-1):
            up = max(A[i]+K, A[n-1]-K)
            down = min(A[0]+K, A[i+1]-K)
            mindis = min(mindis, up-down)
        return min(mindis, A[n-1]-A[0])# 第二种情况为同侧偏置