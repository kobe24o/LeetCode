class Solution:
    def newInteger(self, n: int) -> int:
        num = []
        while n:
            num.append(n%9)
            n //= 9
        ans = 0
        for i in range(len(num)-1,-1,-1):
            ans = ans*10+num[i]
        return ans