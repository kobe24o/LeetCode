class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
    	vector<int> count(n, 0);
        int s = rounds[0]-1, e;
    	for(int i = 0; i < rounds.size()-1; ++i)
    	{
            e = rounds[i+1]-1;
    		while(s != e)
    		{
    			count[s]++;
    			s++;
    			if(s == n)
    				s = 0;
    		}
            count[s]++;
            s = (e+1)%n;
    	}
    	int maxcount = *max_element(count.begin(), count.end());
    	vector<int> ans;
    	for(int i = 0; i < n; i++)
    	{
    		if(count[i] == maxcount)
    			ans.push_back(i+1);
    	}
    	return ans;
    }
};