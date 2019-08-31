class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0)
        	return {0};
        int i, j, num = 0, len;
        vector<int> ans;
        ans.push_back({0});
        for(i = 0; i < n; ++i)
        {
        	len = ans.size();
        	for(j = len-1; j >= 0; --j)	
        	{
        		num = ans[j]|(1<<i);
        		ans.push_back(num);
        	}
        }
        return ans;
    }
};
