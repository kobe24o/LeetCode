int func(int x, int y)
{
	if(y%2 == 0)
		return x+y;
	else
		return x;
}
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = accumulate(A.begin(), A.end(),0,func);
        for(auto it = queries.begin(); it != queries.end(); ++it)
        {
        	if(((*it)[0]+A[(*it)[1]]) % 2 == 0)
        	{
        		if(A[(*it)[1]]%2 == 0)
        		{
        			sum += (*it)[0];
        		}
        		else
        		{
        			sum += (*it)[0]+A[(*it)[1]];
        		}
        		A[(*it)[1]] += (*it)[0];
        		ans.push_back(sum);
        	}
        	else
        	{
        		if(A[(*it)[1]]%2 == 0)
        		{
        			sum -= A[(*it)[1]];
        		}
        		A[(*it)[1]] += (*it)[0];
        		ans.push_back(sum);
        	}
        }
        return ans;
    }
};