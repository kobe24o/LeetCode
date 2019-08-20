#include <vector>
#include <climits>

using namespace std;
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int minPieces = INT_MAX;
        money(coins, amount, 0, 0, minPieces);
        if(minPieces != INT_MAX)
            return minPieces;
        else
            return -1;
    }
    void money(vector<int>& coins, int &amount, int curMoney, int curPieces, int &minPieces)
    {
        if(curMoney > amount)
        {
            curPieces = INT_MAX;//表示不存在
            return;
        }
        if(curMoney == amount)
        {
            if(curPieces < minPieces)
                minPieces = curPieces;
            return;
        }
        for(int i = 0; i < coins.size(); ++i)
        {
            money(coins, amount,curMoney+coins[i], curPieces+1, minPieces)；
        }
    }
};