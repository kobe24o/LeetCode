class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    	int l = 1, r = heights.size()-1, ans = 0, mid;
    	while(l <= r)
    	{
    		mid = l +((r-l)>>1);
    		if(canjump(heights, bricks, ladders, mid))
    		{
    			ans = mid;
    			l = mid+1;
    		}
    		else
    			r = mid-1;
    	}
    	return ans;
    }
    bool canjump(vector<int>& heights, int bricks, int ladder, int dest)
    {
    	vector<int> g;
    	for(int i = 1; i <= dest; i++)
    		if(heights[i]-heights[i-1] > 0)
    		    g.push_back(heights[i]-heights[i-1]);
    	sort(g.begin(), g.end(), greater<int>());
        int i = 0;
    	for(; i < g.size(); i++)
    	{
    		if(ladder)
    			ladder--;
    		else if(bricks-g[i] >= 0)
    			bricks -= g[i];
            else if(bricks-g[i] < 0)
                break;
    	}
    	return i == g.size();
    }
};

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    	priority_queue<int,vector<int>,greater<int>> q;//小顶堆
    	int needbricks = 0;
    	for(int i = 1; i < heights.size(); i++) 
    	{
    		int h = heights[i]-heights[i-1];
    		if(h > 0)
    		{
    			q.push(h);
    			if(q.size() > ladders)
    			{
    				needbricks += q.top();
    				q.pop();
    			}
    			if(needbricks > bricks)
    				return i-1;
    		}
    	}
    	return heights.size()-1;
    }
};