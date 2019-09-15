class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right, maxlen = 0;
        for(right = 0; right < A.size(); ++right) 
        {
        	if(A[right]==0)
        	{
        		if(K == 0)
        		{
        			while(A[left] == 1)//等于0退出
        				++left;
        			++left;//退出了一个0
        		}
        		else//k不为0，0变成1的数量还没满
	        	{
	        		--K;
	        	}
        	}	
        	maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};