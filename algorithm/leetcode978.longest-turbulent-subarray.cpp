class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
    	int i, n = A.size(), maxlen = 1;
    	vector<int> dp0(n,1), dp1(n,1);
    	//dp0,表示以下降结束，dp1表示以上升结束
    	// 到位置 i 处的最长长度
    	for(i = 1; i < n; i++)
    	{
    		if(A[i-1] > A[i])//需要前面是上升,现在是下降
    			dp0[i] = dp1[i-1] + 1;
    		else if(A[i-1] < A[i])
    			dp1[i] = dp0[i-1] + 1;
    		maxlen = max(maxlen, max(dp0[i],dp1[i]));
    	}
    	return maxlen;
    }
};