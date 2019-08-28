class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int buy = prices[0], sell, profit = 0, maxProfit = 0, secondMaxProfit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
        	if(prices[i] >= prices[i-1])//股票值钱了
    		{
    			if(i == prices.size()-1)
                {
                    sell = prices[i];
                    profit = sell - buy;
                    if(profit >= maxProfit)
                    {
                        secondMaxProfit = maxProfit;
                        maxProfit = profit;
                    }
                    else if(profit > secondMaxProfit && profit < maxProfit)
                    	secondMaxProfit = profit;
                }
            }
        	else//不值钱了
        	{
        		sell = prices[i-1];
        		profit = sell - buy;
        		buy = prices[i];
        		if(profit >= maxProfit)
                {
                    secondMaxProfit = maxProfit;
                    maxProfit = profit;
                }
                else if(profit > secondMaxProfit && profit < maxProfit)
                	secondMaxProfit = profit;
        	}
        }
        return maxProfit+secondMaxProfit;
    }
};

int main()
{
	vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
	Solution s;
	std::cout << s.maxProfit(prices);
	return 0;
}