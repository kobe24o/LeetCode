class Solution {
public:
    int countTriplets(vector<int>& A) {
    	vector<int> count(1<<16, -1);//两个数 & 操作后，不会变大
    	for(int i = 0; i < A.size(); ++i)
    	{
    		for(int j = 0; j < A.size(); ++j)
    		{
    			count[A[i] & A[j]]++;
    		}
    	}
    	int ans = 0;
    	for(int i = 0; i < A.size(); ++i)
    	{
    		for(int j = 0; j < (1<<16); ++j)
    		{
    			if(A[i] & j == 0)
    				ans++;
    		}
    	}
    	return ans;
    }
};