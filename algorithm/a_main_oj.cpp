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
    int numFriendRequests(vector<int>& ages) {
        vector<int> age(121, 0);//每个年龄有多少人
        for(auto a : ages)
            age[a]++;
        vector<int> sum(121,0);
        for(int i = 1; i <= 120; i++)
        {
            sum[i] += sum[i-1];// 前缀人数和
        }
        int ans = 0, l, r;
        for(int i = 15; i <= 120; i++)
        {
            l = i/2 + 7;
            r = i;
            ans += (sum[r-1]-sum[l])*age[i]+age[i]*(age[i]-1)/2;//减去自己
        }
        return ans;
    }
};
//"0010 0110 0100 111"
//001001100100111
//001001100100111
int main()
{
    vector<int> l = {16,16};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{15,96},{36,2}};
     Solution s;
    string str = "abb";

    cout << s.numFriendRequests(l) <<endl;



    cout << "hello" << endl;
    system("pause");
    return 0;
}


