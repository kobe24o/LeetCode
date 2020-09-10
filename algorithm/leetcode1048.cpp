- 先按长度排序
- 建立字符串与其序号的哈希映射
- `dp[i]` 表示以单词 `i`结束的链的最大长度
见代码注释

```cpp
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[&](auto a, auto b){
            return a.size() < b.size();//按长度排序
        });
        int n = words.size(), maxlen = 1, i, j, k;
        unordered_map<string, int> s;//哈希
        string tmp;
        vector<int> dp(n, 1);
        for(i = 0; i < n-1; ++i)
        {
            s[words[i]] = i;//建立哈希
            for(j = i+1; j < n; ++j)
            {
                if(words[j].size() != words[i].size()+1)
                    break;//长度相差不为1，结束
                for(k = 0; k < words[j].size(); ++k)
                {   //遍历后面长的单词，枚举所有少一个字符的子串
                    tmp = words[j].substr(0,k)+words[j].substr(k+1);
                    if(s.find(tmp) != s.end())//存在这个子串
                    {
                        dp[j] = max(dp[j], dp[s[tmp]]+1);
                        maxlen = max(maxlen, dp[j]);
                    }
                }
            }
        }
        return maxlen;
    }
};
```
196 ms  25.2 MB