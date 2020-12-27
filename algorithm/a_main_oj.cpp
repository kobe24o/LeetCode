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
// Solution
class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        int l = 1, r = *max_element(L.begin(),L.end())+1, mid, maxlen = 0;
        while(l <= r)
        {
        	mid = l+((r-l)/2);
        	if(ok(L, mid, k))
        	{
        		maxlen = mid;
        		l = mid+1;
        	}
        	else
        		r = mid-1;
        }
        return maxlen;
    }
    bool ok(vector<int> &L, int len, int k)
    {
    	int count = 0;
    	for(int i = 0; i < L.size(); i++)
    	{
    		count += L[i]/len;
    	}
    	return count >= k;
    }
};

int main()
{

    Solution s;
    vector<int> a = {1,2,3}, b = {2,2,3, 4};
    string s1 = "D450";
    cout << s.woodCut(a,7) << endl;


    return 0;
}