class Solution:
    def findLucky(self, arr: List[int]) -> int:
        ans = sorted(filter(lambda x :x[0]==x[1], zip(set(arr),map(arr.count,set(arr)))), key = lambda x:x[0])
        return ans[-1][0] if ans else -1;