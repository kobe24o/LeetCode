class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int i,j,sum = 0, count;
        for(i = 0; i < m; ++i)
        {
        	if(A[i][0] == 0)//把最高位翻成1,他的比重，比后面最大和还大1
        	{
        		for(j = 0; j < n; ++j)
        			A[i][j] = (A[i][j] == 0 ? 1 : 0);
        	}
        }
        sum += m*(1<<(n-1));

        //除第0列外，按列，取1多的方法翻转
        for(j = 1; j < n; ++j)
        {
        	count = 0;
        	for(i = 0; i < m; ++i)
        	{
        		if(A[i][j]==0)
        			count++;
        	}
        	if(count >= (m+1)/2)//0比较多，直接改成1
        		sum += count*(1<<(n-j-1));
        	else
        		sum += (m-count)*(1<<(n-j-1));
        }
        return sum;
    }
};