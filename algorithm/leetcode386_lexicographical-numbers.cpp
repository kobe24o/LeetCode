class Solution {
public:
    vector<int> lexicalOrder(int n) {
    	vector<int> ans(n);
    	int cur = 1;
    	for(int i = 0; i < n; ++i)
    	{
    		ans[i] = cur;
    		if(cur*10 <= n)
    			cur *= 10;//1，10,100,1000,11,110，
    		else
    		{
    			if(cur >= n)
    				cur /= 10;
    			cur += 1;
    			while(cur%10 == 0)
    				cur /= 10;
    		}
    	}
    	return ans;
    }
};

class Solution {
	vector<int> ans;
public:
    vector<int> lexicalOrder(int n) {
        for(int i=1; i<=9; i++)
            dfs(i, n);
        return ans;
    }
    void dfs(int cur, int n)
    {
        if(cur > n)
        	return;
        ans.push_back(cur);
        for(int i=0;i<10;i++)
        {
            if(10*cur + i > n)
                return;
            dfs(10*cur+i, n);
        }
    }
};