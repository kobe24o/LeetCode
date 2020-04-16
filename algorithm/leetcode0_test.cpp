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

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if(pattern==value)
            return true;
        else if(pattern=="" && value!="")
            return false;
        int i, a = 0, b = 0, vlen = value.size();
        for(i = 0; i < pattern.size(); ++i)
        {
            if(pattern[i]=='a')
                a++;
            else
                b++;
        }
        if(a==0 || b==0)
        {
            if(value=="")
                return true;
            a = max(a, b);
            return onlyAorB(value, a);
        }
        //a,b均有的情况
        //a，b均可以表示空字符串
        if(onlyAorB(value,a))//b表示空串
            return true;
        if(onlyAorB(value,b))//a表示空串
            return true;
        //a，b均不表示空
        int la=1, lb=1;//a,b代表的长度
        while(la*a < vlen)
        {
            if((vlen-la*a)%b)//不能整除
            {
                la++;
                continue;
            }
            lb = (vlen-la*a)/b;
            if(good(la,lb,pattern,value))
                return true;
            la++;
        }
        return false;
    }
    bool onlyAorB(string& val, int a)
    {
        if(val.size()%a)
            return false;
        int n = val.size()/a;
        string sub = val.substr(0,n);
        for(int j = n; j < val.size(); j+=n)
        {
            if(val.substr(j,n) != sub)
                return false;
        }
        return true;
    }
    bool good(int la, int lb, string& pat, string& val)
    {
        int idxa = -1, idxb = -1, i = 0, idx = 0;
        while(idxa==-1 || idxb==-1)
        {
            if(pat[i]=='a')
            {
                if(idxa == -1)
                    idxa = idx;
                idx += la;
            }
            else
            {
                if(idxb == -1)
                    idxb = idx;
                idx += lb;
            }
            i++;
        }
        string sa = val.substr(idxa, la);
        string sb = val.substr(idxb, lb);
        int j = 0, delta;
        for(i = 0; i < pat.size(); ++i, j+=delta)
        {
            if(pat[i]=='a')
            {
                delta = la;
                if(val.substr(j,la) != sa)
                    return false;
            }
            else
            {
                delta = lb;
                if(val.substr(j,lb) != sb)
                    return false;
            }
        }
        return true;
    }
};

//["01","10","0","1","1001010"] 9
//["01","0","0101010"]  6
//["011000","0111010","01101010"] 9
//["011000","0111011","01001010"] 11
//["01","1000000","11111111"] 13
//则当前节点所构成的最大距离即左深度+右深度-2*当前节点深度。

//["...1","..S.","..*.",".0.T"]   9
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
//    vector<vector<int>> v6 = {{-13260,8589},{1350,8721},{-37222,-19547},{-54293,-29302},{-10489,-13241},{-19382,574},{5561,1033},{-22508,-13241},{-1542,20695},{9277,2820},{-32081,16145},{-50902,23701},{-8636,19504},{-17042,-28765},{-27132,-24156},{-48323,-4607},{30279,29922}};
    vector<vector<int>> v6 ={{1,1,1},{1,0,1},{1,1,1}};
    vector<int> v1 = {68,130,64};
    vector<int> v2 = {-230,194,7};
    vector<int> v3 = {-1,0};
    vector<int> v4 = {3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v5 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"hjhbr", "dixpgflm", "jjzgr", "gb", "ruzih", "zvthz", "rcadj", "agched", "jwvouurr", "hpmyrbq", "rdzfv", "pdffy", "ihsvg", "dihvb", "fhdwixmy", "cpvhj", "x", "aotsh", "qgahgz", "upoij"};
    vector<string> st1 = {};
    Solution s;
    s.patternMatching("ab"
                   ,"");
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