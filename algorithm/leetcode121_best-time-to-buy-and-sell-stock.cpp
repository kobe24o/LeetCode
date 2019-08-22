#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int minprice = prices[0], curprofit, maxprofit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] < minprice)
                minprice = prices[i];
            curprofit = prices[i] - minprice;
            if(curprofit > maxprofit)
                maxprofit = curprofit;
        }
        return maxprofit;
    }
};