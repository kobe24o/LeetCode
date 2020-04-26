class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> l(k+2,0);
        vector<int> r(k+2,0);
        int len = 1, i;
        for(i = 0; i < k; ++i,++len)
            l[len] = cardPoints[i]+l[len-1];
        len = 1;
        for(i = cardPoints.size()-1; len <= k; --i,++len)
            r[len] = cardPoints[i]+r[len-1];
        int maxScore = 0;
        for(len = 0; len <= k; ++len)
            maxScore = max(maxScore, l[len]+r[k-len]);
        return maxScore;
    }
};