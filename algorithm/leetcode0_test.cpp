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

using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        //去除尾部空格
        while(!s.empty() && s.back() == ' ')
            s.pop_back();
        while(!s.empty() && s.front() == ' ')
            s.erase(s.begin());//忽略头部空格
        if(s.empty())
            return false;
        if(!isdigit(s[0]) && s[0] != '.' && s[0] != '+' && s[0] != '-')
            return false;
        int i, n = s.size();
        multimap<char,int> m;
        for(i = 0; i < n; ++i)
        {
            if(s[i]=='+' || s[i] =='-')
                m.insert(make_pair('+',i));
            else if(s[i]=='-')
                m.insert(make_pair('-',i));
            else if(s[i]=='e' || s[i]=='E')
                m.insert(make_pair('E',i));
            else if(s[i]=='.')
                m.insert(make_pair('.',i));
            else if(s[i] == ' ' || !isdigit(s[i]))
                return false;
        }

        auto s1 = m.lower_bound('E');
        auto e1 = m.upper_bound('E');
        auto pe = m.find('E');
        auto pdot = m.find('.');
        if(distance(s1,e1) > 1 || (m.count('E') && pe->second==n-1))
            return false;
        s1 = m.lower_bound('.');
        e1 = m.upper_bound('.');
        if(distance(s1,e1) > 1)
            return false;
        if(m.count('.') && ((m.count('E') && pe->second < pdot->second) ||(n==1)))
            return false;
        s1 = m.lower_bound('+');
        e1 = m.upper_bound('+');
        int d = distance(s1,e1);
        if(d > 2)
            return false;
        else if(d == 1)
        {
            if(!m.count('E') && s1->second != 0)
                return false;
            else if(s1->second != 0 && (m.count('E') && s1->second != pe->second+1))
                return false;
            else if(s1->second == n-1)
                return false;
        }
        else if (d == 2)
        {
            if(!m.count('E'))
                return false;
            if(s1->second != 0 || (++s1)->second != pe->second+1)
                return false;
            else if(s1->second == n-1)
                return false;
        }
        if(s.find(".e") == 0 || s.find(".E") == 0  || s.find("+.") != string::npos || s.find("-.") != string::npos)
            return false;
        return true;
    }
};


int main() {
    Solution s;

    vector<vector<int>> v = {{1,3,2},{4,6,5},{7,9,8},{13,15,14},{10,12,11}};
    vector<int> v1 = {5,6};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{3,2}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    cout << s.isNumber("+.8") << endl;
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
    return 0;
}