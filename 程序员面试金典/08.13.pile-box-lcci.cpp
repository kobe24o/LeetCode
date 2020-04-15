class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
    	sort(box.begin(), box.end(),[&](auto a, auto b) {
    		return a[0] > b[0];//宽降序
    	});
    	int i, j, n = box.size();
    	vector<int> dp(n,0);//以i箱子为顶的最大高度
    	for(i = 0; i < n; ++i)
    	{
    		dp[i] = box[i][2];//初始化自身高度
    		for(j = 0; j < i; ++j)//跟前面的比较
    		{
    			if(box[i][0] < box[j][0] && box[i][1] < box[j][1]
    					&& box[i][2] < box[j][2])//满足条件
    			{
    				dp[i] = max(dp[i], box[i][2]+dp[j]);//可以叠加，取最大的
    			}
    		}
    	}
    	return *max_element(dp.begin(),dp.end());
    }
};