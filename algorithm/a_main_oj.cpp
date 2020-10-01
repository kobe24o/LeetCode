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
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        int layer = 0, full = 0, up_l, up_r;
        dp[0][0] = poured;
        for(int i = 1; i <= query_row; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                up_l = j > 0 ? dp[i-1][j-1] : 0;
                up_r = dp[i-1][j];
                dp[i][j] += up_l > 1 ? (up_l-1)/2.0 : 0;
                dp[i][j] += up_r > 1 ? (up_r-1)/2.0 : 0;
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};
//"0010 0110 0100 111"
//001001100100111
//001001100100111
int main()
{
    vector<int> l = {-8,-4,-2,-1,0,0,1,2,4,8};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{15,96},{36,2}};
     Solution s;
    string str = "abb";

    cout << s.champagneTower(4,2,0) <<endl;



    cout << "hello" << endl;
    system("pause");
    return 0;
}


