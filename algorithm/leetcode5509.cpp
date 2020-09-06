class Solution {
public:
    int minCost(string s, vector<int>& cost) {
    	int sum = 0, temp = cost[0], MAX = cost[0];
    	s += '*';
        cost.push_back(0);
    	for(int i = 1; i < s.size(); i++) 
    	{
    		if(s[i] == s[i-1])
    		{
    			temp += cost[i];
    			MAX = max(MAX, cost[i]);
			}	
			else
			{
				sum += temp-MAX;
				temp = cost[i];
				MAX = cost[i];
			}
    	}
    	return sum;
    }
};