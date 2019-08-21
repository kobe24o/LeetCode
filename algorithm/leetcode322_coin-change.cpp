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

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1)
            return 0;
        int states[amount+1];
        int i, j;
        for(i = 0; i <= amount; ++i)
            states[i] = amount+1;//找i元钱，不可能需要amount+1张
        states[0] = 0;
        for(i = 0; i <= amount; ++i)
        {
            for(j = 0; j < coins.size(); ++j)
            {
                if(i-coins[j] >= 0 && states[i] > states[i-coins[j]]+1)
                {
                    states[i] = states[i-coins[j]]+1;
                }
            }
        }
        if(states[amount] != amount+1)
            return states[amount];
        else
            return -1;
    }
};
int main()
{
    vector<int> coins = {2};
    Solution s;
    cout << s.coinChange(coins,3);
    return 0;
}