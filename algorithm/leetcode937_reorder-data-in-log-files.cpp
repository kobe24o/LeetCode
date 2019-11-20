#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string getStr(const string &s, string &pre)
{
    int i = 0;
    while(s[i] != ' ')
    {
        pre += s[i];
        i++;
    }
    return s.substr(i+1);
}

bool cmp(string a, string b)
{
    string preA, preB;
    string sa = getStr(a,preA), sb = getStr(b,preB);
    if((isdigit(sa[0]) && isdigit(sb[0])))
        return false;
    else if((isdigit(sa[0]) && !isdigit(sb[0])))
        return false;
    else if((!isdigit(sa[0]) && isdigit(sb[0])))
        return true;
    else
    {
        if(sa != sb)
            return sa < sb;
        else
            return preA < preB;
    }
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};
int main()
{
    vector<string> v ={"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    Solution s;
    s.reorderLogFiles(v);
}