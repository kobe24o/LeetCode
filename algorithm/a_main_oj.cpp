#include <bits/stdc++.h>

using namespace std;
void print2Dvector(vector<vector<int>>& a)
{
    int m = a.size(), n = a[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

struct cmp{
    bool operator()(char a, char b) const
    {
        return a > b;
    }
};
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
    	int n = nums.size(), ans = nums[0], maxNegative = INT_MIN, idx = -1;
    	for(int i = 1; i < n; ++i)
    	{
    		int step = k;
    		bool inNegativePos = true;
    		bool reachEnd = false;
    		for( ; i < n && step--; i++)
    		{
    			if(nums[i] >= 0)
    			{
    				ans += nums[i];
    				inNegativePos = false;
    				break;
    			}
    			else
    			{
    				if(i == n-1)
    					reachEnd = true;
    				if(nums[i] > maxNegative)
    				{
    					maxNegative = nums[i];
    					idx = i;
    				}
    			}
    		}
    		if(inNegativePos)
    		{
    			if(reachEnd)
    			{
    				ans += nums[n-1];
    				break;
    			}
    			else
    			{
	    			ans += nums[idx];
	    			i = idx;
	    		}
    		}
    	}
    	return ans;
    }
};
int main()
{

    Solution s;
    vector<int> a = {100,-1,-100,-1,100}, b = {2,2,3, 4};
    string s1 = "D450";
    cout << s.maxResult(a,2) << endl;


    return 0;
}