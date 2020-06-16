class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        scoreA = A[0]+0
        score = 0
        for i in range(1, len(A)):
            score = max(score, scoreA+A[i]-i)
            scoreA = max(scoreA, A[i]+i)
        return score