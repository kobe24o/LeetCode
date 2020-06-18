class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        maxlen = 0
        for i in range(len(nums)):
            if nums[i] == -1:
                continue
            idx = i
            length = 0
            while idx != -1 and nums[idx] != -1:
                length += 1
                prev = idx
                idx = nums[idx]
                nums[prev] = -1
            maxlen = max(maxlen, length)
        return maxlen
