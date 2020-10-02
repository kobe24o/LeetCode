class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int points = 0, maxPoints = 0, n = tokens.size();
        sort(tokens.begin(), tokens.end());
        if(n==0 || P < tokens[0])
            return 0;
        int l = 0, r = n-1;
        while(l <= r)
        {
            if(P >= tokens[l])//能量够，去拿分
            {
                points++;
                P -= tokens[l];//消耗最少的能量
                l++;
            }
            else//能量不够
            {
                if(points > 0)
                {
                    points--;//花分去获取大能量
                    P += tokens[r];
                    r--;
                }
                else
                    break;
            }
            maxPoints = max(points, maxPoints);
        }
        return maxPoints;
    }
};