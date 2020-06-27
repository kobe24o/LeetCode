class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxlen = 0
        lr = []
        l, r = -1, -1
        for i in range(len(nums)):
            if nums[i] and l==-1:
                l = i
            if l != -1 and nums[i]==0 and r==-1:
                r = i-1
            if nums[i] and i == len(nums)-1:
                r = len(nums)-1
            if l != -1 and r != -1:
                lr.append([l,r])
                l, r = -1, -1

        if len(lr)==0:
            return 0
        if len(lr)==1:
            if lr[0][0]!=0 or lr[0][1]!=len(nums)-1:
                return lr[0][1]-lr[0][0]+1
            else:
                return len(nums)-1
        maxlen = max(maxlen, lr[0][1]-lr[0][0]+1)
        for i in range(len(lr)-1):
            j = i+1
            if lr[i][1]+2==lr[j][0]:
                maxlen = max(maxlen, lr[j][1]-lr[i][0])
            else:
                maxlen = max(maxlen, lr[j][1]-lr[j][0]+1)
        return maxlen