#include <vector>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;
//class Solution//回溯超时
//{
//public:
//    int coinChange(vector<int>& coins, int amount)
//    {
//        int minPieces = INT_MAX;
//        money(coins, amount, 0, 0, minPieces);
//        if(minPieces != INT_MAX)
//            return minPieces;
//        else
//            return -1;
//    }
//    void money(vector<int>& coins, int &amount, long curMoney, int curPieces, int &minPieces)
//    {
//        if(curMoney > amount)
//        {
//            curPieces = INT_MAX;//表示不存在
//            return;
//        }
//        if(curMoney == amount)
//        {
//            if(curPieces < minPieces)
//                minPieces = curPieces;
//            return;
//        }
//        for(int i = 0; i < coins.size(); ++i)
//        {
//            money(coins, amount,curMoney+coins[i], curPieces+1, minPieces)；
//        }
//    }
//};

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if(amount < 1)
            return 0;
        int *states = new int [amount+1];
        int n = amount/coins[0]+1, i, j, k;
        memset(states, INT_MAX, sizeof(states)*(amount+1));
//        for(i = 0; i < coins.size(); ++i)
//            states[coins[i]] = 1;
        for(i = 0; i < n; ++i)
        {
            for(j = amount; j >= 0; --j)
            {
                if(states[j] != INT_MAX)
                {
                    for(k = 0; k < coins.size(); ++k)
                    {
                        if(j+coins[k] <= amount && states[j+coins[k]] > states[j]+1)
                            states[j+coins[k]] = states[j]+1;
                    }
                }
            }
        }
        if(states[amount] != INT_MAX)
            return states[amount];
        else
            return -1;
    }
};
int main()
{
    vector<int> coins = {1,2,3};
    Solution s;
    cout << s.coinChange(coins,6);
    return 0;
}