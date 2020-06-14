class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i, j, n = prices.size();
        for(i = 0; i < n-1; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if(prices[j] <= prices[i])
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};