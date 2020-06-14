class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        sum = 0
        minlen = float('inf')
        m = {}
        m[0] = -1
        left, right = [0]*n, [0]*n
        for i in range(n):
            sum += arr[i]
            m[sum] = i
            if sum-target in m:
                minlen = min(minlen,i-m[sum-target])
            left[i] = minlen
        m = {}
        m[0] = n
        sum = 0
        minlen = float('inf')
        for i in range(n-1, -1,-1):
            sum += arr[i]
            m[sum] = i
            if sum-target in m:
                minlen = min(minlen, m[sum-target]-i)
            right[i] = minlen
        minlen = float('inf')
        for i in range(n-1):
            if left[i] != float('inf') and right[i+1] != float('inf'):
                minlen = min(minlen, left[i]+right[i+1])
        if minlen == float('inf'):
            return -1
        return minlen