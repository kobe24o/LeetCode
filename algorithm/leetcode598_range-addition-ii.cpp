class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty())
            return m*n;
    	int r = INT_MAX, c = INT_MAX;
        for(auto it = ops.begin(); it != ops.end(); ++it)
        {
        	if(r > (*it)[0])
        		r = (*it)[0];
        	if(c > (*it)[1])
        		c = (*it)[1];
        }
        return r*c;
    }
};