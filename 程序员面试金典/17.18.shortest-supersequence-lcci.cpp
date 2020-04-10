class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
    	if(big.size() < small.size())
    		return {};
    	int i=0, j=0, n = big.size(), k = small.size(), minLen = INT_MAX;
    	vector<int> ans(2,-1);
    	unordered_set<int> s;
    	unordered_map<int,int> m;
    	for(int c : small)
    		s.insert(c);
    	while(j < n)
    	{
    		while(j < n && m.size() < k)
    		{
    			if(s.count(big[j]))
    				m[big[j]]++;
    			j++;
    		}
    		
    		while(i < j && m.size()==k)
    		{
    			if(j-i < minLen)
	    		{
	    			minLen = j-i;
	    			ans[0] = i, ans[1] = j-1;
	    		}
    			if(s.count(big[i]))
    			{
    				m[big[i]]--;
    				if(m[big[i]]==0)
    					m.erase(big[i]);
    			}
    			i++;
    		}
    	}
    	if(ans[0]==-1)
    		return {};
    	return ans;
    }
};