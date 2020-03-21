class Solution {    //超时
public:
    int maxBoxes(vector<vector<int>> &boxes) {
        if(boxes.empty())
            return 0;
    	for(auto& b : boxes)
    		if(b[0] > b[1])
    			swap(b[0],b[1]);
        sort(boxes.begin(),boxes.end(),[&](auto a, auto b)
        	{
        		if(a[0] == b[0])
        			return a[1] < b[1];
        		return a[0] < b[0];
        	});
        int i, j, n = boxes.size();
        vector<int> dp(n, 1);
        for(i = 1; i < n; ++i)
        {
        	for(j = i-1; j >= 0; --j)
        	{
        		if(boxes[i][0] > boxes[j][0] && boxes[i][1] > boxes[j][1])
        			dp[i] = max(dp[i], 1+dp[j]);
        	}
        }
        return *max_element(dp.begin(),dp.end());
    }
};