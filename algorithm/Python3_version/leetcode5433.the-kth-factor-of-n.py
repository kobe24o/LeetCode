class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        s = set()
        for i in range(1,n+1):
            if n%i == 0:
                s.add(i)
        if len(s) < k:
            return -1
        l = list(s)
        l.sort()
        return l[k-1]