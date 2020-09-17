class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        n = len(S)
        for i in range(n-2, -1, -1): 
        # 前面的需要移动多次，逆序前缀和
            shifts[i] = (shifts[i] + shifts[i+1])%26
        ans = list(S)
        for i in range(n):
            ans[i] = chr((ord(ans[i])-ord('a')+shifts[i])%26 + ord('a'))
        return "".join(ans)