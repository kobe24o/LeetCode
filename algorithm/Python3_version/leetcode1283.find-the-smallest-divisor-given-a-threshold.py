class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        l, r = 1, 1000000
        n = len(nums)
        while l < r:
            mid = l+((r-l)>>1)
            sum = 0
            for i in range(n):
                sum += ceil(nums[i]/mid)
            if sum > threshold:
                l = mid+1
            else:
                r = mid
        return l