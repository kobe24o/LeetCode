class Solution:
    def isPalindrome(self, x: int) -> bool:
        a = str(x)
        return "".join(reversed(a))==a