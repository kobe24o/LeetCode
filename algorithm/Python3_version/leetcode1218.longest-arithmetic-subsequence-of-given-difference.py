class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        d = {}
        maxlen = 1
        for i in range(len(arr)):
            if arr[i]-difference in d:
                d[arr[i]] = d[arr[i]-difference] + 1
            else:
                d[arr[i]] = 1
            maxlen = max(maxlen, d[arr[i]])
        return maxlen