class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if(boardingCost*4 <= runningCost)//肯定挣不到钱
            return -1;
        int t = -1, maxProfit = INT_MIN, profit=0, n = customers.size();
        int people = 0, getup;
        for(int i = 0; i < n || people > 0; i++)
        {
            if(i < n)//来了多少游客
                people += customers[i];
            if(people > 0)//还有游客在等待
            {
                getup = min(4, people);//一次上去最多4个
                profit += getup*boardingCost;//收入
                people -= getup;//游客少了几个
            }
            profit -= runningCost;//一次运行成本
            if(profit > maxProfit)//更新最大值
            {
                maxProfit = profit;
                if(maxProfit > 0)
                    t = i+1;
            }
        }
        return t;
    }
};