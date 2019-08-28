class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int buy = prices[0], sell, profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] >= prices[i-1])//股票值钱了
            {
                if(i == prices.size()-1)
                {
                    sell = prices[i];
                    profit += sell - buy;
                }
            }
            else//不值钱了
            {
                sell = prices[i-1];
                profit += sell - buy;
                buy = prices[i];
            }
        }
        return profit;
    }
};