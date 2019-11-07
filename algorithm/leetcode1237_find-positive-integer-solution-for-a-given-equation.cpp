class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        int x = 1, y = 1000, val;
        vector<vector<int>> ans;
        while(x < y)
        {
        	val = cf.f(x,y);
        	if(val < z)
        		x++;
        	else if(val > z)
        		y--;
        	else
        	{
        		ans.push_back({x,y});
        		x++;
        	}
        }
        x = 1000, y = 1;
        while(y < x)
        {
        	val = cf.f(x,y);
        	if(val < z)
        		y++;
        	else if(val > z)
        		x--;
        	else
        	{
        		ans.push_back({x,y});
        		x--;
        	}
        }
        if(z == cf.f(x,y))
            ans.push_back({x,y});
        return ans;
    }
};