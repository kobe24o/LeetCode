class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int i, j, n = arr.size(), idx;
        vector<int> dp(n, 0);//dp数组
        multimap<int, int> m;
        for (i = 0; i < n; i++)
        	m.insert(make_pair(arr[i],i));//map有序，默认升序，按数值排序了
        for(auto& it : m)
        {	//从低到高开始dp
        	idx = it.second;//下标
        	if(dp[idx] == 0)//dp[idx]没有填写过
        	{
        		dp[idx] = 1;//至少为1，自己本身
        		for(j = idx-1; j >= idx-d && j>=0 && arr[idx] > arr[j]; j--)
        		{	//往左边跳，遇到比我高的停止
	        		dp[idx] = max(dp[idx], 1+dp[j]);
        		}
        		for(j = idx+1; j <= idx+d && j<n && arr[idx] > arr[j]; j++)
        		{	//往右边跳，遇到比我高的停止
	        		dp[idx] = max(dp[idx], 1+dp[j]);
        		}
        	}
        }
        return *max_element(dp.begin(),dp.end());//取最大值
    }
};