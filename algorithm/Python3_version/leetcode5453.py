class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        t = 0
        for pos in left:
            t = max(t, pos)
        for pos in right:
            t = max(t, n-pos)
        return t