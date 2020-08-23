class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
    	int n = arr.size(), i, ans = -1;
    	vector<vector<int>> pos(n+2, vector<int>(2, -1));
    	vector<int> len(n+1, 0);
    	int l1,r1,l2,r2,n1,n2,nall,l,r;
    	for(i = 0; i < n; ++i)
    	{
    		l = r = arr[i];
    		nall = 1;
    		n1 = n2 = 0;
    		if(pos[l-1][0] != -1)
    		{
    			l1 = pos[l-1][0];
    			r1 = pos[l-1][1];
    			n1 = r1-l1+1;
    		}
    		if(pos[l+1][0] != -1)
    		{
    			l2 = pos[l+1][0];
    			r2 = pos[l+1][1];
    			n2 = r2-l2+1;
    		}
    		if(n1)
    		{
    			l = min(l, l1);
    			nall += n1;
    			len[n1]--;
    		}
    		if(n2)
    		{
    			r = max(r, r2);
    			nall += n2;
    			len[n2]--;
    		}
            len[nall]++;
    		pos[l][0] = l;
    		pos[l][1] = r;
    		pos[r][0] = l;
    		pos[r][1] = r;
    		if(len[m])
    			ans = i+1;
    	}
    	return ans;
    }
};