class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        i, j, count, product = 0, 0, 0, 1
        while j < n:
            if product*nums[j] < k:
                product *= nums[j]
                count += j-i+1
                j += 1
            else:
                product /= nums[i]
                i += 1
                if i > j:
                    j += 1
                    product = 1
        return count