class Solution {
	vector<int> ch = {0,1,6,8,9};
	int sum = 0;
public:
    int confusingNumberII(int N) {
        vector<int> s = {1,6,8,9};
        for(int i = 0; i < s.size(); i++)
        	dfs(s[i], N);
        return sum;
    }
    void dfs(long long n, int N) 
    {
    	if(n > N)
    		return;
    	if(isok(n))
    		sum++;
    	for(int i = 0; i < ch.size(); i++)
    		dfs(n*10+ch[i], N);
    }
    bool isok(long long n)
    {
    	long long num = 0, bit, origin = n;
    	while(n)
    	{
    		bit = n%10;
    		n /= 10;
    		if(bit==6) bit = 9;
    		else if(bit== 9) bit = 6;
    		num = num * 10 + bit;
    	}
    	return num != origin;
    }
};

class Solution {
public:
    int confusingNumberII(int N) {
        queue<long long> q;
        vector<int> ch = {0,1,6,8,9};
        q.push(1);
        q.push(6);
        q.push(8);
        q.push(9);
        int sum = 0;
        while(!q.empty())
        {
            long long n = q.front();
            q.pop();
            if(isok(n) && n <= N)
                sum++;
            for(int i = 0; i < ch.size(); i++)
            {
                if(n*10+ch[i] <= N)
                    q.push(n*10+ch[i]);
            }
        }
        return sum;
    }
    bool isok(long long n)
    {
        long long num = 0, bit, origin = n;
        while(n)
        {
            bit = n%10;
            n /= 10;
            if(bit==6) bit = 9;
            else if(bit== 9) bit = 6;
            num = num * 10 + bit;
        }
        return num != origin;
    }
};