#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int minprice = prices[0], curprofit, maxProfit = 0, secondMaxProfit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] < minprice)
                minprice = prices[i];
            curprofit = prices[i] - minprice;
            if(curprofit >= maxProfit)
            {
                secondMaxProfit = maxProfit;
                maxProfit = curprofit;
            }
            else if(curprofit > secondMaxProfit && curprofit < maxProfit)
                secondMaxProfit = curprofit;
        }
        return maxProfit+secondMaxProfit;
    }
};


int main()
{
	vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
	Solution s;
	cout << s.maxProfit(prices);
	return 0;
}