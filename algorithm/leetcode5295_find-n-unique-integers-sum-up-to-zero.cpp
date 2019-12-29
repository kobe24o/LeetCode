class Solution {
public:
    vector<int> sumZero(int n) {
    	vector<int> ans(n);
    	int i, k = 0;
        if(n%2 == 0)
        {
        	for(i = 1; i <= n/2; i++)
        	{
        		ans[k++] = i;
        		ans[k++] = -i;
        	}
        }
        else
        {
        	for(i = 1; i <= n/2; i++)
        	{
        		ans[k++] = i;
        		ans[k++] = -i;
        	}
        	ans[k] = 0;
        }
        return ans;
    }
};