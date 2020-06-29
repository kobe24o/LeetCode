class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        l, r = 0, 0
        for i in range(1,len(A)):
            if A[i-1] > A[i]:
                l, r = i-1, i
            elif A[i] < A[l] and A[i] > A[r]:
                r = i
        t = A[l]
        A[l] = A[r]
        A[r] = t
        return A