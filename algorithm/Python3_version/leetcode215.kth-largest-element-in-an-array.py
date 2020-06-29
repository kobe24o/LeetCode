class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def findk(l, r, k):
            p = nums[l];
            i = l
            j = r
            while i < j:
                while i < j and nums[j] > p:
                    j -= 1
                while i < j and nums[i] <= p:
                    i += 1
                t = nums[i]
                nums[i] = nums[j]
                nums[j] = t
            t = nums[i]
            nums[i] = nums[l]
            nums[l] = t
            if i == k:
                return nums[i]
            elif i < k:
                return findk(i+1, r, k)
            else:
                return findk(l, i-1, k)
        return findk(0,len(nums)-1, len(nums)-k)