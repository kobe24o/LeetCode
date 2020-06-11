class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
    	string ans;
    	int i, j, k;
    	bool ok;
    	for(i = 0; i < d.size(); ++i)
    	{
    		j = k = 0;
    		for(; j <s.size() && k<d[i].size(); ++j)
    		{
    			if(s[j] == d[i][k])
    				k++;
    		}
    		if(k == d[i].size())
    		{
    			if(d[i].size() > ans.size())
    				ans = d[i];
    			else if(d[i].size() == ans.size() && d[i] < ans)
    				ans = d[i];
    		}
    	}
    	return ans;
    }
};