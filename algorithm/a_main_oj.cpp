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
    /**
     * @param num: sequence
     * @return: The longest valley sequence
     */
    int valley(vector<int> &num) {
        // write your code here
        int n = num.size();
        if(n <= 1) return 0;
        vector<int> up(n, 1), down(n, 1);//最长递增数组
        for(int i = 0, j; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if(num[j] < num[i])
                    down[j] = max(down[j], down[i] + 1);
            }
        }
        for(int i = n-1, j; i >= 0; i--)
        {
            for(j = i-1; j >= 0; j--)
            {
                if(num[j] < num[i])
                    up[j] = max(up[j], up[i] + 1);
            }
        }
        int maxlen = 0;
        for(int i = 0, j; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if(num[i] == num[j])
                {
                    maxlen = max(maxlen, down[i]+up[j]);
                }
            }
        }
        return maxlen;
    }
};
//"0010 0110 0100 111"
//001001100100111
//001001100100111
int main()
{
    vector<int> l = {2,1,0,1,2,3,4,5};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{15,96},{36,2}};
     Solution s;
    string str = "abb";

    cout << s.valley(l) <<endl;



    cout << "hello" << endl;
    system("pause");
    return 0;
}


