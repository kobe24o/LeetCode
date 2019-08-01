class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
    	int n = triangle.size();
        int states[n];
        int temp_states[n];
        states[0] = triangle[0][0];
        int i, j, k, minsum = INT_MAX;
        for (i = 1; i < n; i++)
        {
        	for(j = 0; j < i+1; j++)
        	{
        		if(j == 0)
        			temp_states[0] = states[0] + triangle[i][j];
        		else if(j == i)
        			temp_states[j] = states[j-1] + triangle[i][j];
        		else
        			temp_states[j] = min(states[j-1], states[j]) + triangle[i][j];
        	}
        	for(k = 0; k < i+1; k++)
        		states[k] = temp_states[k];//更新states
        }
        for(j = 0; j < n; j++)//求最小的值
        {
        	if(states[j] < minsum)
        		minsum = states[j];
        }
        return minsum;
    }
};