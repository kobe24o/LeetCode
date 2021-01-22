class Solution {
public:
    int maxRepOpt1(string text) {
        text.push_back('-');//方便代码处理
        vector<vector<vector<int>>> p(26);
        // 存放每个字符每个连续段的 {开始位置，结束位置}
        char prev = text[0];
        int start = 0, ans = 1;
        for(int i = 0; i < text.size(); ++i)
        {
            if(text[i] != prev)
            {
                p[prev-'a'].push_back({start, i-1});
                ans = max(ans, i-start);//什么都不做的情况下的最大长度
                start = i;
                prev = text[i];
            }
        }

        for(int i = 0; i < 26; ++i)
        {
            int len = p[i].size();//有多少段该字符
            for(int j = 1; j < len; ++j)
            {
                int prevEnd = p[i][j-1][1];
                int n1 = p[i][j-1][1]-p[i][j-1][0]+1;
                int curStart = p[i][j][0];
                int n2 = p[i][j][1]-p[i][j][0]+1;
                if(curStart-prevEnd == 2)//隔一个字符
                {
                    ans = max(ans, n1+n2+(len>2 ? 1 : 0));
                }
                else//间隔多个字符
                {
                    ans = max(ans, max(n1+1, n2+1));
                }
            }
        }
        return ans;
    }
};