class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int i, n = prices.size(), moneyNoCash = 0, moneyHoldCash = -prices[0];
        for(i = 1; i < n; ++i)
        {
        	moneyNoCash = max(moneyNoCash, moneyHoldCash+prices[i]-fee);
        	moneyHoldCash = max(moneyHoldCash, moneyNoCash-prices[i]);
	    }
	    return moneyNoCash;
    }
};