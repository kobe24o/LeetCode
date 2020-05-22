class Solution {
public:
    vector<int> beautifulArray(int N) {
    	if(N == 1)
    		return {1};
    	vector<int> odd = beautifulArray((N+1)/2);
    	vector<int> even = beautifulArray(N/2);
    	vector<int> ans;
    	for(int i : odd)
    		ans.push_back(i*2-1);
    	for(int i : even)
    		ans.push_back(i*2);
    	return ans;
    }
};

class Solution {
public:
    vector<int> beautifulArray(int N) {
    	vector<int> temp = {1};
    	int i, j = 0, len;
    	while(temp.size() < N)
    	{
    		len = temp.size();
    		for(i = 0; i < len; ++i)
    			temp[i] = 2*temp[i]-1;
    		for(i = 0; i < len; ++i)
    			temp.push_back(temp[i]+1);
    	}
    	vector<int> ans(N);
    	for(i = 0; i < temp.size(); ++i)
    	{
    		if(temp[i] <= N)
    			ans[j++] = temp[i];
    	}
    	return ans;
    }
};