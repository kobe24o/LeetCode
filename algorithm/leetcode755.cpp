class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
    	int l = K, r = K, n = heights.size();
    	while(V)//还有水
    	{
    		l = K;
    		while(l >= 1 && heights[l-1] <= heights[l])//左边有更低的
    			l--;
    		while(l < K && heights[l] == heights[l+1])//一样高，靠近k处
    			l++;
    		if(l != K)
    		{
    			heights[l]++;
    			V--;
    			continue;
    		}
    		r = K;
    		while(r <= n-2 && heights[r] >= heights[r+1])//右边有更低的
    			r++;
    		while(r > K && heights[r-1] == heights[r])
    			r--;
    		heights[r]++;
    		V--;
    	}
    	return heights;
    }
};