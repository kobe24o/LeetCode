class Solution {
public:
    int totalFruit(vector<int>& tree) {
    	unordered_map<int,int> m;
    	int i = 0, j = 0, n = tree.size(), maxf = 0;
    	while(j < n)
    	{
    		if(m.size() > 2)
    		{
    			m[tree[i]]--;
    			if(m[tree[i]]==0)
    				m.erase(tree[i]);
    			i++;
    		}
    		m[tree[j]]++;
            if(m.size() <= 2)
                maxf = max(maxf, j-i+1);
    		j++;
    	}
    	return maxf;
    }
};