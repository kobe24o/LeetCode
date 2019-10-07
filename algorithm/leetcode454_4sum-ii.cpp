class Solution {
	int *ab, *cd;
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size(), i, j, k = 0, ans = 0;
        int N = n*n;
        ab = new int[N];
        cd = new int[N];
        for(i = 0; i < n; ++i)
        	for(j = 0; j < n; ++j)
        		ab[k++] = A[i]+B[j];
    	k = 0;
    	for(i = 0; i < n; ++i)
        	for(j = 0; j < n; ++j)
        		cd[k++] = -C[i]-D[j];
        sort(cd,cd+N);
        for(i = 0; i < N; ++i)
        {
        	ans += findV(ab[i], N);
        }
        return ans;
    }
    int findV(int &val, int &N)
    {
    	int i = 0, j = N-1, mid, count = 0, idx;
    	while(i <= j)
    	{
    		mid = i+((j-i)>>1);
    		if(val == cd[mid])
    		{
    			idx = mid-1;
    			while(idx >= 0 && cd[idx--] == val)
    				++count;
    			idx = mid+1;
    			while(idx < N && cd[idx++] == val)
    				++count;
    			return count+1;
    		}
    		else if(val < cd[mid])
    			j = mid-1;
    		else
    			i = mid+1;
    	}
    	return 0;
    }
};

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size(), i, j, ans = 0;
        unordered_map<int, int> m;
        for(i = 0; i < n; ++i)
        	for(j = 0; j < n; ++j)
        		if(m.find(A[i]+B[j]) == m.end())
        			m[A[i]+B[j]] = 1;
        		else
        			m[A[i]+B[j]]++;
    	for(i = 0; i < n; ++i)
        	for(j = 0; j < n; ++j)
        		if(m.find(-C[i]-D[j]) != m.end())
        			ans += m[-C[i]-D[j]];
        return ans;
    }
};