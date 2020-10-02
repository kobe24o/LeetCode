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
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        set<int> s, temp;//记录顺序未确定的
        for(int i = 0; i < n; ++i)
            s.insert(i);
        int del = 0;
        for(int j = 0; j < n; ++j)
        {
            bool order = true, equal = false;
            char prev = 'a'-1;
            int previd = -1;
            for(auto i : s)
            {
                if(prev == A[i][j])
                {
                    equal = true;
                    temp.insert(previd);
                    temp.insert(i);
                }
                else if(prev > A[i][j])
                {
                    del++;
                    order = false;
                    break;
                }
                prev = A[i][j];
                previd = i;
            }
            if(order && !equal)
                break;
            if(order && equal)
            {
                s = temp;
                temp.clear();
            }
        }
        return del;
    }
};
//"0010 0110 0100 111"
//001001100100111
//001001100100111
int main()
{
    vector<int> l = {100,200,300,400};
    vector<string> str = {"abx","agz","bgc","bfc"};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{15,96},{36,2}};
    Solution s;

    cout << s.minDeletionSize(str) <<endl;



    cout << "hello" << endl;
    system("pause");
    return 0;
}


