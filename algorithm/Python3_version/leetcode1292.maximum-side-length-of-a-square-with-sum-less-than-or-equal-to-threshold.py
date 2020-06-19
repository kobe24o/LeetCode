class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        maxlen = 0
        prefixsum = [[0]*n for _ in range(m)]
        prefixsum[0][0] = mat[0][0]
        for j in range(1,n):
            prefixsum[0][j] = prefixsum[0][j-1]+mat[0][j]
        for i in range(1,m):
            prefixsum[i][0] = prefixsum[i-1][0]+mat[i][0]
        for i in range(1,m):
            for j in range(1,n):
                prefixsum[i][j] = prefixsum[i-1][j]+prefixsum[i][j-1]-prefixsum[i-1][j-1]+mat[i][j]
        for i in range(m):
            for j in range(n):
                length = maxlen+1
                while length <= min(m,n):
                    ni = i+length-1
                    nj = j+length-1
                    if ni<m and nj<n and prefixsum[ni][nj]-(prefixsum[i-1][nj] if i > 0 else 0)-(prefixsum[ni][j-1] if j > 0 else 0)+(prefixsum[i-1][j-1] if i>0 and j>0 else 0) <= threshold:
                        maxlen = max(maxlen, length)
                        if maxlen == min(m,n):
                            return maxlen
                    else:
                        break
                    length += 1
        return maxlen