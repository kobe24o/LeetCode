class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), i, j, maxlen = 0;
        int cost[n], costs = 0;
        for(i = 0; i < n; ++i)
            cost[i] = abs(s[i]-t[i]);//计算每个位置的花费
        for(i=0, j=0; j < n; ++j)//建立左右[i,j]的窗口
        {
            costs += cost[j];
            if(costs <= maxCost)
            {
                maxlen = max(maxlen, j-i+1);
            }
            else
            {
                while(costs > maxCost)
                {
                    costs -= cost[i];
                    i++;
                }
                maxlen = max(maxlen, j-i+1);
            }
        }
        return maxlen;
    }
};