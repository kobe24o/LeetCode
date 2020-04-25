class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    	vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    	int steps = 1, step, count = 1, i, j, k = 0, delta = 0;
    	vector<vector<int>> ans = {{r0,c0}};
    	while(count < R*C)
    	{
    		step = steps;
    		while(step--)
    		{
    			r0 += dir[k][0];
    			c0 += dir[k][1];
    			if(r0>=0&& r0<R && c0>=0&&c0<C)
    			{
    				ans.push_back({r0,c0});
                    // cout << r0 << " " << c0 << endl;
    				count++;
    			}
    		}
    		k = (k+1)%4;
    		delta++;
    		if(delta%2==0)
    		{
    			delta = 0;
    			steps++;
    		}
    	}
    	return ans;
    }
};