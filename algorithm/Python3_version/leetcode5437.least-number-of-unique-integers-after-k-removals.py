class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        d = {}
        for i in arr:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        count = list(d.values())
        # count.sort()
        count = sorted(count)
        i = 0
        for c in count:
            k -= c
            if k >= 0:
                i += 1
            if k <= 0:
                break
        return len(count) - i