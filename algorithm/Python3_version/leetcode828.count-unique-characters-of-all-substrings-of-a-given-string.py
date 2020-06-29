class Solution:
    def uniqueLetterString(self, s: str) -> int:
        count = 0
        for j in range(len(s)):
            i = j-1 
            k = j+1
            while i>=0 and s[i]!=s[j]:
                i -= 1
            while k<len(s) and s[j]!=s[k]:
                k += 1
            count = (count+(j-i)*(k-j))%1000000007
        return count