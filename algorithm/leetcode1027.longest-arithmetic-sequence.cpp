class Solution {//错误解，差有可能有一样的
public:
    int longestArithSeqLength(vector<int>& A) {
    	int i, j, d, n = A.size(), maxlen = 2;
    	unordered_map<int,unordered_map<int,int>> m;//差为多少，尾数是多少，最大长度
    	for(i = 1; i < n; i++) 
    	{
    		for(j = i-1; j >= 0; --j)
    		{
    			d = A[i]-A[j];
    			if(m.count(d) && m[d].count(A[j]))
    				m[d][A[i]] = max(m[d][A[j]] + 1, m[d][A[i]]);
    			else
    				m[d][A[i]] = max(m[d][A[i]], 2);
    			maxlen = max(maxlen, m[d][A[i]]);
    		}
    	}
    	return maxlen;
    }
};

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
    	int i, j, d, n = A.size(), maxlen = 2;
    	unordered_map<int,unordered_map<int,int>> m;//idx，差，最大长度
    	for(i = 0; i < n; i++) 
    	{
    		for(j = i-1; j >= 0; --j)
    		{
    			d = A[i]-A[j];
    			if(m[j][d])
    				m[i][d] = max(m[i][d], m[j][d] + 1);
    			else
    				m[i][d] = max(m[i][d], 2);
    			maxlen = max(maxlen, m[i][d]);
    		}
    	}
    	return maxlen;
    }
};

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
    	int i, j, d, n = A.size(), maxlen = 2;
    	vector<vector<int>> m(n,vector<int>(20001,0));//m[idx][差]，最大长度
    	for(i = 0; i < n; i++) 
    	{
    		for(j = i-1; j >= 0; --j)
    		{
    			d = A[i]-A[j];
    			if(d < 0)
    				d = -d + 10000;
    			if(m[j][d])
    				m[i][d] = max(m[i][d], m[j][d] + 1);
    			else
    				m[i][d] = max(m[i][d], 2);
    			maxlen = max(maxlen, m[i][d]);
    		}
    	}
    	return maxlen;
    }
};