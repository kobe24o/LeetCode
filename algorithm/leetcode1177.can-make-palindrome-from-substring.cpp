class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int i, j, l, r, n = queries.size(), odd;
        vector<vector<int>> count(s.size(),vector<int>(26,0));
        vector<int> temp(26,0);
        vector<bool> ans(n);
        for(i = 0; i < s.size(); ++i)
        {
        	temp[s[i]-'a']++;
        	count[i] = temp;
        }
        for(i = 0; i < n; ++i)
        {
        	l = queries[i][0];
        	r = queries[i][1];
        	temp = count[r];
        	if(l-1>=0)
        	{
        		for(j = 0; j < 26; ++j)
        			temp[j] -= count[l-1][j];
        	}
        	odd = 0;
        	for(j = 0; j < 26; ++j)
        		if(temp[j]%2)
        			odd++;
            if((r-l)%2)//长度偶数
    		    ans[i] = (odd-2*queries[i][2]<=0);
            else
                ans[i] = (odd-1-2*queries[i][2]<=0);
        }
        return ans;
    }
};