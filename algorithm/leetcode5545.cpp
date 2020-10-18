class Solution {
    typedef pair<int, int> pii;
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pii> score_Age(n);
        for(int i = 0; i < n; i++) 
        {
            score_Age[i] = {scores[i], ages[i]};
        }
        sort(score_Age.begin(), score_Age.end(),[&](auto& a, auto& b){
            return (a.second < b.second || (a.second == b.second && a.first < b.first));
        });//年龄小的在前，同龄的话，能力小的在前
        //然后DP寻找上升子序的最大和
        vector<int> dp(n, 0);
        dp[0] = score_Age[0].first;
        int maxscore = dp[0];
        for(int i = 1; i < n; ++i)
        {
            int curscore = score_Age[i].first;
            dp[i] = score_Age[i].first;//初始化为自己的分数
            for(int j = i-1; j >= 0; j--)
            {
                int prevscore = score_Age[j].first;
                if(curscore >= prevscore)
                {   //当前人的能力值不是下降的, 加入队伍
                    dp[i] = max(dp[i], dp[j]+curscore);
                }
            }
            maxscore = max(maxscore, dp[i]);
        }
        return maxscore;
    }
};