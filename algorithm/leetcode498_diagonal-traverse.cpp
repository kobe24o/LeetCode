class Solution {
	int r,c;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0, k;
        r = matrix.size(), c = matrix[0].size();
        vector<int> ans;
        bool up = true;
        while(i != r-1 || j != c-1)
        {
        	ans.push_back(matrix[i][j]);
        	if(up)
        	{
        		i -= 1;
        		j += 1;
        		if(!inrange(i,j))
        		{
        			up = false;
        			if(j <= c-1)
        				i += 1;
        			else
        				j -= 1, i -= 2;
        		}
        	}
        	else//down
        	{
        		i += 1;
        		j -= 1;
        		if(!inrange(i,j))
        		{
        			up = true;
        			if(i <= r-1)
        				j += 1;
        			else
        				i += 1, j += 2;
        		}
        	}
        }
        ans.push_back(matrix[i][j]);
        return ans;
    }
    bool inrange(int &i, int &j)
    {
    	return (i>=0 && i <r && j>=0 && j <c);
    }
};