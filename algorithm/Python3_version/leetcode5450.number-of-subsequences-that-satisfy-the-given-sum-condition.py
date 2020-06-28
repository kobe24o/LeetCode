class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        mod = int(1e9+7)
        nums.sort()
        def bs(t):
            i,j = 0, len(nums)-1
            while i <= j:
                mid = (i+j)>>1
                if nums[mid] > t:
                    j = mid-1
                else:
                    if mid==len(nums)-1 or nums[mid+1] > t:
                        return mid
                    else:
                        i = mid+1
            return -1
        def mypow(n):
            s, p = 1, 2
            while n:
                if n&1:
                    s *= p
                    s %= mod
                p *= p
                p %= mod
                n //= 2
            return s
        count = 0
        for i in range(len(nums)):
            if nums[i] > target//2+1:
                break;
            j = bs(target-nums[i])
            if j != -1 and j >= i:
                count = (count + mypow(j-i))%mod
        return count