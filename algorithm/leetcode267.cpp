class Solution {
	vector<string> ans;
	int n;
public:
    vector<string> generatePalindromes(string s) {
        vector<int> count(128,0);
        n = s.size();
        for(char ch : s)
        	count[ch]++;
        int odd = 0, idx;
        for(int i = 0; i < 128; ++i)
        {
        	if(count[i]&1)
        	{
        		odd++;
        		idx = i;
        	}
        	if(odd > 1)
        		return {};
        }
        s = odd ? string(1, idx) : "";
        odd ? count[idx]-- : 0;
        dfs(count,s);
        return ans;
    }

    void dfs(vector<int>& count, string s)
    {
    	if(s.size()==n)
    	{
    		ans.push_back(s);
    		return;
    	}
    	for(int i = 0; i < 128; ++i)
    	{
    		if(count[i])
    		{
    			count[i] -= 2;
    			dfs(count,char(i)+s+char(i));
    			count[i] += 2;
    		}
    	}
    }
};