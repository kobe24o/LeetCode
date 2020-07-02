class Solution:
    def removeVowels(self, S: str) -> str:
        s = set(['a','e','i','o','u'])
        ans = ""
        for ch in S:
            if ch not in s:
                ans += ch
        return ans