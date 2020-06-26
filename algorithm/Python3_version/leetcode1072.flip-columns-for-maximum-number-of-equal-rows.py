class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        d = {}
        s = [' ']*(len(matrix[0]))
        for mat in matrix:
            if mat[0]==0:
                for i in range(len(mat)):
                    mat[i] ^= 1
                    s[i] = '1' if mat[i] else '0'
            else:
                for i in range(len(mat)):
                    s[i] = '1' if mat[i] else '0'
            strs = ''.join(s)
            if strs in d:
                d[strs] += 1
            else:
                d[strs] = 1
        maxcount = 0
        for key in d:
            maxcount = max(maxcount, d[key])
        return maxcount