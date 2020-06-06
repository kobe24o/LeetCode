class Solution {
public:
    int balancedString(string s) {
        int n = s.size(), Q = 0, W = 0, E = 0, R = 0;
        int nt = n>>2;
        int i = 0, j, minlen = n;
        for(i = 0; i < n; ++i)
        {   //获取计数
            if (s[i] == 'Q') Q++;
            else if (s[i] == 'W') W++;
            else if (s[i] == 'E') E++;
            else R++;
        }
        if(Q==nt && W==nt && E==nt && R==nt)
            return 0;//已平衡，满足
        for(i = 0, j = 0; j < n; ++j)
        {
            if(Q > nt || W > nt || E > nt || R > nt)
            {   //窗口外多了，进入窗口一个，窗口外少了，计数-1
                if (s[j] == 'Q') Q--;
                else if (s[j] == 'W') W--;
                else if (s[j] == 'E') E--;
                else R--;
            }
            while(i < n && (Q <= nt && W <= nt && E <= nt && R <= nt))
            {   //窗口外满足条件，我要尽可能的让窗口小，让左端点出去，窗口外计数+1
                minlen = min(minlen, j-i+1);
                if (s[i] == 'Q') Q++;
                else if (s[i] == 'W') W++;
                else if (s[i] == 'E') E++;
                else R++;
                i++;
            }
        }
        return minlen;
    }
};