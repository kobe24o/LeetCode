class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        l, r = 0, 0
        maxlen = 0
        while r < len(A):
            if A[r]==0:
                K -= 1
            while K < 0:
                if A[l]==0:
                    K += 1
                l += 1
            r += 1
            maxlen = max(maxlen, r-l)    
        return maxlen