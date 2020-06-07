class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        op1, op2 = 0, 0
        n = len(nums)
        for i in range(n):
            cur = nums[i]
            if i&1:
                if cur >= nums[i-1]:
                    op1 += cur-nums[i-1]+1
                    cur = nums[i-1]-1
                if i+1 < n and cur >= nums[i+1]:
                    op1 += cur-nums[i+1]+1
            else:
                if i>0 and cur >= nums[i-1]:
                    op2 += cur-nums[i-1]+1
                    cur = nums[i-1]-1
                if i+1 < n and cur >= nums[i+1]:
                    op2 += cur-nums[i+1]+1
        return min(op1, op2)