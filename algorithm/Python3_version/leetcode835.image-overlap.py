class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        n = len(A)
        maxoverlap = 0
        offset = [[0]*(2*n+1) for _ in range(2*n+1)]
        for i in range(n):
            for j in range(n):
                if A[i][j]:
                    for x in range(n):
                        for y in range(n):
                            if B[x][y]:
                                offset[i-x+n][j-y+n] += 1
        for i in range(2*n+1):
            for j in range(2*n+1):
                maxoverlap = max(maxoverlap, offset[i][j])
        return maxoverlap