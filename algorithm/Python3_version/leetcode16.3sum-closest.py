class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        minDiffer, record = float('inf'), 0
        cursum = nums[0]+nums[1]+nums[2];
        if target <= cursum:
            return cursum
        n = len(nums)
        cursum = nums[n-3]+nums[n-2]+nums[n-1]
        if target >= cursum:
            return cursum
        for i in range(n-2):
            s = i+1
            e = n-1
            while s < e:
                cursum = nums[i]+nums[s]+nums[e]
                if abs(cursum-target) < minDiffer:
                    minDiffer = abs(cursum-target)
                    record = cursum
                if cursum < target:
                    s += 1
                elif cursum == target:
                    return cursum
                else:
                    e -= 1
        return record