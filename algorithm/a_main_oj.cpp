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
     * @param n: The folding times
     * @return: the 01 string
     */
    string getString(int n) {
        // Write your code here
        if(n==1) return "0";
        string ans, temp = "0";
        while(--n)
        {
            int flag = 0, size = temp.size();
            for(int i = 0; i < temp.size(); i++)
            {
                ans += string(1, flag+'0')+temp[i];
                flag = (flag==0 ? 1 : 0);
            }
            ans += "1";
            temp = ans;
            ans = "";
        }
        return temp;
    }
};
//"0010 0110 0100 111"
//001001100100111
//001001100100111
int main()
{
    vector<int> l = {6,3,5};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{15,96},{36,2}};
     Solution s;
    string str = "abb";

    cout << s.getString(3) <<endl;



    cout << "hello" << endl;
    system("pause");
    return 0;
}


