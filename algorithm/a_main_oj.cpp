#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
#include<algorithm>
using namespace std;
#include <string>     // std::string, std::stoi
#include <map>
#include<stack>

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    /**
     * @param triangle: Coordinates of three points
     * @param point: Xiaoqi's coordinates
     * @return: Judge whether you can cast magic
     */
    string castMagic(vector<vector<int>> &triangle, vector<int> &point) {
        // write your code here
        for(int i = 0; i < 3; i++)
        {
            if(!ok(triangle[i],triangle[(i+1)%3],triangle[(i+2)%3],point))
                return "No";
        }
        return "Yes";
    }

    bool ok(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p)
    {
        int x1 = p1[0], y1 = p1[1], x2 = p2[0], y2 = p2[1], x3 = p3[0], y3 = p3[1];
        int xi = p[0], yi = p[1];
        int v1 = (y2-y1)*(x3-x1)-(y3-y1)*(x2-x1);
        int v2 = (y2-y1)*(xi-x1)-(yi-y1)*(x2-x1);
        cout << v1 << " " << v2 << endl;
        if(v1*v2 < 0)//异号，说明，我的位置不在第3点的一侧
            return false;
        return true;
    }
};
int main()
{
    vector<int> l = {2,1};
    vector<vector<int>> t = {{0,0},{2,0},{1,1}};
    Solution s;
    string str = "bacbdab";
    cout << s.castMagic(t, l) <<endl;
    //读出二进制文件中的内容并输出到显示器6
    system("pause");
    return 0;
}


