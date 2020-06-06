/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class dsu
{
public:
    vector<int> f;

    dsu(int n)
    {
        f.resize(n+1);
        for(int i = 0; i < n+1; ++i)
            f[i] = i;
    }
    void merge(int a, int b)
    {
        f[a] = b;
    }
    int find(int a)
    {
        int origin = a;
        while(a != f[a])
            a = f[a];
        return f[origin] = a;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        map<string, map<pair<int,int>,string>> m;
        string name, city, prevcity;
        int time, amount, prevtime, prevamount, n, i;
        for(string& tr : transactions)
        {
            name = city = "";
            time = amount = n = 0;
            for(i = 0; i < tr.size(); i++)
            {
                if(tr[i] == ',')
                {
                    n++;
                    continue;
                }
                if(n == 0)
                    name += tr[i];
                else if(n == 1)
                    time = time*10+tr[i]-'0';
                else if(n == 2)
                    amount = amount*10+tr[i]-'0';
                else
                    city += tr[i];
            }
            m[name][make_pair(time, amount)] = city;
        }
        vector<string> ans;
        bool processPrev;
        string cur, prev;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            name = it->first;
            processPrev = false;
            prevtime = -1;
            for(auto it1 = m[name].begin(); it1 != m[name].end(); ++it1)
            {
                time = it1->first.first;
                amount = it1->first.second;
                city = it1->second;
                if(prevtime != -1)
                {
                    if(amount>1000 || (time-prevtime <= 60 && prevcity != city))
                    {
                        cur = name+","+to_string(time)+","+to_string(amount)+","+city;
                        prev = name+","+to_string(prevtime)+","+to_string(prevamount)+","+prevcity;
                        if(!processPrev && time-prevtime <= 60 && prevcity != city)
                            ans.push_back(prev);
                        ans.push_back(cur);
                        processPrev = true;
                    }
                    else
                        processPrev = false;
                }
                else//第一个
                {
                    if(amount > 1000)
                    {
                        cur = name+","+to_string(time)+","+to_string(amount)+","+city;
                        ans.push_back(cur);
                        processPrev = true;
                    }
                }
                prevtime = time;
                prevamount = amount;
                prevcity = city;
            }
        }
        return ans;
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
//    vector<vector<int>> v6 = {{-13260,8589},{1350,8721},{-37222,-19547},{-54293,-29302},{-10489,-13241},{-19382,574},{5561,1033},{-22508,-13241},{-1542,20695},{9277,2820},{-32081,16145},{-50902,23701},{-8636,19504},{-17042,-28765},{-27132,-24156},{-48323,-4607},{30279,29922}};
    vector<vector<int>> v6 ={{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> v5 ={{0,4},{4,0},{1,3},{3,0}};
    vector<int> v1 = {197,130,1};
    vector<int> v2 = {2,3,4};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};

    vector<string> st1 = {"bob,649,842,prague","alex,175,1127,mexico","iris,164,119,paris","lee,991,1570,mexico","lee,895,1876,taipei","iris,716,754,moscow","chalicefy,19,592,singapore","chalicefy,820,71,newdelhi","maybe,231,1790,paris","lee,158,987,mexico","chalicefy,415,22,montreal","iris,803,691,milan","xnova,786,804,guangzhou","lee,734,1915,prague","bob,836,1904,dubai","iris,666,231,chicago","iris,677,1451,milan","maybe,860,517,toronto","iris,344,1452,bangkok","lee,664,463,frankfurt","chalicefy,95,1222,montreal","lee,293,1102,istanbul","maybe,874,36,hongkong","maybe,457,1802,montreal","xnova,535,270,munich","iris,39,264,istanbul","chalicefy,548,363,barcelona","lee,373,184,munich","xnova,405,957,mexico","chalicefy,517,266,luxembourg","iris,25,657,singapore","bob,688,451,beijing","bob,263,1258,tokyo","maybe,140,222,amsterdam","xnova,852,330,barcelona","xnova,589,837,budapest","lee,152,981,mexico","alex,893,1976,shenzhen","xnova,560,825,prague","chalicefy,283,399,zurich","iris,967,1119,guangzhou","alex,924,223,milan","chalicefy,212,1865,chicago","alex,443,537,taipei","maybe,390,5,shanghai","bob,510,1923,madrid","bob,798,343,hongkong","iris,643,1703,madrid","bob,478,928,barcelona","maybe,75,1980,shanghai","xnova,293,24,newdelhi","iris,176,268,milan","alex,783,81,moscow","maybe,560,587,milan","alex,406,776,istanbul","lee,558,727,paris","maybe,481,1504,munich","maybe,685,602,madrid","iris,678,788,madrid","xnova,704,274,newdelhi","chalicefy,36,1984,paris","iris,749,200,amsterdam","lee,21,119,taipei","iris,406,433,bangkok","bob,777,542,taipei","maybe,230,1434,barcelona","iris,420,1818,zurich","lee,622,194,amsterdam","maybe,545,608,shanghai","xnova,201,1375,madrid","lee,432,520,dubai","bob,150,1634,singapore","maybe,467,1178,munich","iris,45,904,beijing","maybe,607,1953,tokyo","bob,901,815,tokyo","maybe,636,558,milan","bob,568,1674,toronto","iris,825,484,madrid","iris,951,930,dubai","bob,465,1080,taipei","bob,337,593,chicago","chalicefy,16,176,rome","chalicefy,671,583,singapore","iris,268,391,chicago","xnova,836,153,jakarta","bob,436,530,warsaw","alex,354,1328,luxembourg","iris,928,1565,paris","xnova,627,834,budapest","xnova,640,513,jakarta","alex,119,16,toronto","xnova,443,1687,taipei","chalicefy,867,1520,montreal","alex,456,889,newdelhi","lee,166,3,madrid","bob,65,1559,zurich","alex,628,861,moscow","maybe,668,572,mexico","bob,402,922,montreal"};
    Solution s;
    s.invalidTransactions(st1);
    printv(v4);

    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(0);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(4);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;


    ListNode *h1 = new ListNode(3);
    ListNode *h2 = new ListNode(5);
    ListNode *h3 = new ListNode(8);
    ListNode *h4 = new ListNode(5);
    ListNode *h5 = new ListNode(10);
    ListNode *h6 = new ListNode(2);
    ListNode *h7 = new ListNode(1);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    vector<int> a = {1,2,3};
    cout << a.size() << endl;
    a.resize(a.size()+5);
    cout << a.size() << endl;
    for(int i = 0; i < 8; ++i)
        cout << a[i] << endl;
    return 0;
}