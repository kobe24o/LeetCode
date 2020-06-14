class Solution:
	def longestCommonPrefix(self, strs: List[str]) -> str:
		if not strs:
			return ""
		s1 = min(strs)
		s2 = max(strs)
		n = min(len(s1), len(s2))
		for i in range(n):
			if s1[i] != s2[i]:
				return s1[:i]
		return s1