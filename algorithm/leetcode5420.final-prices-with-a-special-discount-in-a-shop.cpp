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

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i, n = prices.size();
        stack<int> stk;
        vector<int> ans(prices);
        for(i = n-1; i >= 0; --i)
        {
            while(!stk.empty() && prices[i] < prices[stk.top()])
                stk.pop();
            if(!stk.empty())
                ans[i] -= prices[stk.top()];
            stk.push(i);
        }
        return ans;
    }
};