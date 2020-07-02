class Solution:
    def countElements(self, arr: List[int]) -> int:
        s = set(arr)
        count = 0
        for a in arr:
            if a+1 in s:
                count += 1
        return count