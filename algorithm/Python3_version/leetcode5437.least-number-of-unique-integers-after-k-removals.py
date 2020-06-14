class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        d = {}
        for i in arr:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        count = d.values()
        count.sort()
        i = 0
        while k > 0:
            k -= count[i]
            if k >= 0:
                i += 1
        return len(count)-i