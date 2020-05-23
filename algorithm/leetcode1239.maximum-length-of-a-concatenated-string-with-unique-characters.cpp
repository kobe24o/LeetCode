class Solution {
	int maxlen = 0;
public:
    int maxLength(vector<string>& arr) {
    	dfs(arr, 0, 0, 0);
    	return maxlen;
    }

    void dfs(vector<string>& arr, int count, int i, int len)
    {
        maxlen = max(maxlen, len);
        if(i == arr.size())
            return;
        int j, origin = count;
        for(j = 0; j < arr[i].size(); ++j)
        {
            if((count>>(arr[i][j]-'a'))&1)//已经存在该字符
            {
                return dfs(arr, origin, i+1, len);//这个单词不选
            }
            count |= (1<<(arr[i][j]-'a'));
        }
        dfs(arr, origin, i+1, len);//该单词不选	    		
        dfs(arr, count, i+1, len+arr[i].size()); //该单词选
    }
};

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int i, j, n = arr.size(), maxlen = 0, state, nextstate;
        bool ok;
        map<int,int> dp;//字符数状态int表示，最大长度
        dp[0] = 0;
        for(i = 0; i < n; ++i)
        {
            for(auto it = dp.rbegin(); it != dp.rend(); ++it)
            {
                state = it->first;
                nextstate = state;
                ok = true;
                for(j = 0; j < arr[i].size(); ++j)
                {
                    if((nextstate>>(arr[i][j]-'a'))&1)//该位存在
                    {
                        ok = false;
                        break;
                    }
                    nextstate |= (1<<(arr[i][j]-'a'));
                }
                if(ok)
                {
                    dp[nextstate] = max(dp[nextstate], int(dp[state]+arr[i].size()));
                    maxlen = max(maxlen, dp[nextstate]);
                }
            }
        }
        return maxlen;
    }
};
