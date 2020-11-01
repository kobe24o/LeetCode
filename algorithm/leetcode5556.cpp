class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    	int l = 0; r = heights.size()-1, ans = 0, mid;
    	vector<int> gap(heights.size()-1);
    	for(int i = 1; i < heights.size(); i++)
    		gap[i-1] = heights[i]-heights[i-1];
    	while(l <= r)
    	{
    		mid = l +((r-l)>>1);
    		if(canjump(gap, bricks, ladders, mid))
    		{
    			ans = mid;
    			l = mid+1;
    		}
    		else
    			r = mid-1;
    	}
    	return ans;
    }
    bool canjump(vector<int>& gap, int bricks, int ladder, int dest)
    {
    	int 
    }
};