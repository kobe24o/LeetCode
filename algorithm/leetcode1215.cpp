class Solution {
	vector<int> ans;
public:
    vector<int> countSteppingNumbers(int low, int high) {
        if(low == 0) ans.push_back(0);
        queue<int> q;
        for(int i = 1; i <= 9; ++i)
        	q.push(i);
        long long tp, last;
        while(!q.empty())
        {
        	tp = q.front();
        	q.pop();
        	if(tp >= low && tp <= high)
        		ans.push_back(tp);
        	last = tp%10;
            if(last!=0 && tp*10+last-1 <= high)
        		q.push(tp*10+last-1);
        	if(last!=9 && tp*10+last+1 <= high)
        		q.push(tp*10+last+1);	
        }
        return ans;
    }
};

class Solution {
	vector<int> ans;
public:
    vector<int> countSteppingNumbers(int low, int high) {
        if(low == 0) ans.push_back(0);
        for(int i = 1; i <= 9; ++i)
        	dfs(i, low, high);
        sort(ans.begin(), ans.end());
        return ans;
    }
    void dfs(long long n, int low, int high)
    {
    	int last = n%10;
    	if(n >= low && n <= high)
    		ans.push_back(n);
        if(last!=0 && n*10+last-1 <= high)
    		dfs(n*10+last-1, low, high);
    	if(last!=9 && n*10+last+1 <= high)
    		dfs(n*10+last+1, low, high);	
    }
};