#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
#include <string>     // std::string, std::stoi
#include <map>
#include<stack>
# include<queue>
#include<iostream>
#include<string>
using namespace std;

typedef long long ll;
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int s1 = cost.size(), s2 = cost[0].size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, INT_MAX));
        for(int i = 0; i <= s1; i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= s2; i++)
        {
            dp[0][i] = 0;
        }
        for(int i = 1; i <= s1; i++)
        {
            for(int j = 1; j <= s2; j++)
            {
                for(int k = 1; k <= i; ++k)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+cost[k-1][j-1]);
                }
                for(int k = 1; k <= j; ++k)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+cost[i-1][k-1]);
                }
            }
        }
        for(int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[s1][s2];
    }
};


int main()
{
    vector<int> l = {6,3,5,2};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{1,3,5},{4,1,1},{1,5,3}};
    Solution s;
    string str = "bacbdab";
    cout << s.connectTwoGroups(t1) <<endl;
    //读出二进制文件中的内容并输出到显示器6

    return 0;
}


