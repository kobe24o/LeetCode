class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m*k > len(bloomDay):
            return -1
        def haveflower(days):
            flowerPack, flowercount = 0, 0
            for d in bloomDay:
                if days//d >= 1:
                    flowercount += 1
                else:
                    flowercount = 0
                if flowercount == k:
                    flowerPack += 1
                    flowercount = 0
            return flowerPack >= m
        l, r = 1, int(1e9)
        while l < r:
            mid = l+((r-l)>>1)
            if(haveflower(mid)):
                r = mid
            else:
                l = mid+1
        return l