class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        i, j = 0, 0
        count = 0
        st = set()
        while j < len(S):
            while len(st) >= K or S[j] in st:
                st.remove(S[i])
                i += 1
            st.add(S[j])
            if len(st)==K:
                count += 1
            j += 1
        return count