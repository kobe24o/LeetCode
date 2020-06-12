class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        x = 0
        for i in nums:
            x ^= i
        return len(nums)%2==0 or x==0