class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        s = set()
        for a in A:
            if a not in s:
                s.add(a)
            else:
                return a