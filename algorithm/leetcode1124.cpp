class Solution {
public:
    int longestWPI(vector<int>& hours) {
    	int n = hours.size(), i = 0;
    	vector<int> sum(n+1, 0);
    	for(i = 1; i <= n; i++)
    	{
    		sum[i] = (hours[i-1]>8 ? 1 : -1) + sum[i - 1];
    	}
    	stack<int> s;
    	int maxlen = 0;
    	for(i = 0; i < n+1; i++)
    	{
    		if(s.empty() || sum[s.top()] > sum[i])
    		    s.push(i);
    	}
        for(i = n; i >= 0 && !s.empty(); i--)
        {
            while(!s.empty() && sum[i] > sum[s.top()])
            {
                maxlen = max(maxlen, i-s.top());
                s.pop();
            }
        }
    	return maxlen;
    }
};

class Solution {
public:
    int longestWPI(vector<int>& hours) {
    	int n = hours.size(), maxlen = 0, sum=0;
    	unordered_map<int, int> m;
    	for(int i = 0; i < n; ++i)
    	{
            sum += hours[i]>8 ? 1 : -1;
            if(sum > 0)
                maxlen = i+1;
            else
            {
                if(m.count(sum-1))
                    maxlen = max(maxlen, i-m[sum-1]);
                if(!m.count(sum))
                    m[sum] = i;
            }
    	}
    	return maxlen;
    }
};