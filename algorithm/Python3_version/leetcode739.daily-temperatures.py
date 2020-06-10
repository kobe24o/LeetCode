class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n = len(T)
        ans = [0]*n
        s = []
        for i in range(n-1,-1,-1):
            while len(s)>0 and T[i] >= T[s[-1]]:
                s.pop()
            if len(s)>0:
                ans[i] = s[-1]-i
            s.append(i)
        return ans