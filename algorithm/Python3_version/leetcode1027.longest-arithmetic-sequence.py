class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        n = len(A)
        maxlen = 2
        m = [[0]*20001 for _ in range(n)] # m[idx][差]，最大长度
        for i in range(1,n):
            for j in range(0,i):
                d = A[i]-A[j];
                if d < 0:
                    d = -d + 10000;
                if m[j][d]:
                    m[i][d] = max(m[i][d], m[j][d] + 1)
                else:
                    m[i][d] = max(m[i][d], 2)
                maxlen = max(maxlen, m[i][d])
        return maxlen