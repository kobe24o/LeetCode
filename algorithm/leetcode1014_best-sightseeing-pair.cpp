class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int i, j, scores = 0;
        for(i = 0; i < A.size(); ++i)
        {
        	for(j = i+1; j < A.size(); ++j)
        		scores = max(scores, A[i]+A[j]+i-j);
        }
        return scores;
    }
};
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int i, scoresA = A[0]+0, scores = 0;
        for(i = 1; i < A.size(); ++i)
        {
        	scores = max(scores, scoresA + A[i]-i);//历史的A的得分，当前的B得分
        	scoresA = max(scoresA, A[i]+i); //记录最大的A点得分
        }
        return scores;
    }
};