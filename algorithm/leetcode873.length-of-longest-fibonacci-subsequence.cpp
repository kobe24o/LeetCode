class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
    	unordered_set<int> s;
    	for(int Ai : A)
    		s.insert(Ai);
    	int a, b, c, len = 0, maxlen = 0;
    	for(int i = 0, j; i < A.size(); ++i)
    	{
    		for(j = i+1; j < A.size(); ++j)
    		{
                len = 2;
    			c = A[i]+A[j];
                a = A[i];
                b = A[j];
				while(s.count(c))
				{
					len++;
					maxlen = max(maxlen, len);
					a = b;
					b = c;
					c = a+b;
				}
    		}
    	}
    	return maxlen;
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
    	unordered_map<int,int> m;//val, idx
        int i, j, prevAi, idx, maxlen = 0, n = A.size();
    	for(i = 0; i < n; ++i)
    		m[A[i]] = i;
    	vector<vector<int>> dp(n,vector<int>(n,0));
    	//dp[i][j] 表示以 A[i],A[j]结尾的序列长度
    	for(i = 0; i < n; ++i)
    		for(j = i+1; j < n; ++j)
    			dp[i][j] = 2;
    	for(i = 0; i < A.size(); ++i)
    	{
    		for(j = i+1; j < A.size(); ++j)
    		{
    			prevAi = A[j]-A[i];//A[i] 前一位数
                if(m.count(prevAi))
                {
                	idx = m[prevAi];
                	if(idx < i)
                	{
                        dp[i][j] = max(dp[i][j],dp[idx][i]+1);
                        maxlen = max(maxlen,dp[i][j]);
                    }
                }
    		}
    	}
    	return maxlen;
    }
};