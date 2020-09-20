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
        int n = s1+s2+1;
        // 状态压缩DP，将最多24个状态放在二进制位上表示
        // 最终必须全部是1，表示连接起来了
        vector<int> dp(1<<n, INT_MAX);
        dp[0] = 0;//什么都没有连
        for(int i = 0; i < s1; i++)
        {
            for(int j = 0; j < s2; j++)
            {
                for(int state = (1<<n)-1; state >= 0; state--)
                {
                    if(dp[state] == INT_MAX)
                        continue;
                    dp[state|(1<<(i+s2))|(1<<j)] = min(dp[state|(1<<(i+s2))|(1<<j)], dp[state]+cost[i][j]);
                }
            }
        }
        return dp[1<<(n+1)-1];
    }
};


int main()
{
    vector<int> l = {6,3,5,2};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{15,96},{36,2}};
    Solution s;
    string str = "bacbdab";
    cout << s.connectTwoGroups(t1) <<endl;
    //读出二进制文件中的内容并输出到显示器6

    return 0;
}


