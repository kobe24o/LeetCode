class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int i = 0, maxProfit = 0, low = INT_MAX;
    	for(i = 0; i < prices.size(); ++i)
    	{
    		low = min(low, prices[i]);
    		maxProfit = max(maxProfit, prices[i]-low);
    	}
    	return maxProfit;
    }
};