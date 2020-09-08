class Solution {
	vector<int> ans;
public:
    vector<int> numsSameConsecDiff(int N, int K) {
    	if(N == 1)
    		return {0,1,2,3,4,5,6,7,8,9};
    	for(int i = 1; i <= 9; ++i)
    		dfs(1,N,K,i);
    	return ans;
    }
    void dfs(int count, int N, int K, int num)
    {
    	if(count == N)
    	{
    		ans.push_back(num);
    		return;
    	}
    	int last = num%10;
    	if(last+K <= 9)
    		dfs(count+1, N, K, num*10+last+K);
    	if(last-K >= 0 && K != 0) // K 为0,跟上面重复了
    		dfs(count+1, N, K, num*10+last-K);
    }
};