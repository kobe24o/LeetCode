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

struct cmp1{
    bool operator()(pair<int,int> a, pair<int,int> b) const
    {
        if(a.first==b.first&&a.second==b.second)
            return false;
        if(a.first==b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};
struct cmp2{
    bool operator()(pair<int,int> a, pair<int,int> b) const
    {
        if(a.first==b.first&&a.second==b.second)
            return false;
        if(a.second==b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int i, j, n = height.size(),maxP = 1;
        vector<pair<int,int>> p(n);
        for(i = 0; i < n; ++i)
            p[i] = {height[i], weight[i]};
        set<pair<int,int>,cmp1> dp1;
        set<pair<int,int>,cmp2> dp2;
        dp1.insert(p[0]);
        dp1.insert({65,90});
        for(i = 0; i < n; ++i)
        {
            auto it = dp1.upper_bound(p[i]);
            if(it == dp1.end())
                dp1.insert(p[i]);
            else
            {
                dp1.erase(it);
                dp1.insert(p[i]);
            }
        }
        for(i = 0; i < n; ++i)
        {
            auto it = dp2.upper_bound(p[i]);
            if(it == dp2.end())
                dp2.insert(p[i]);
            else
            {
                dp2.erase(it);
                dp2.insert(p[i]);
            }
        }
        return max(dp1.size(),dp2.size());
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
    vector<vector<char>> v4 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<int> v1 = {65,70,56,75,60,68};
    vector<int> v3 = {100,150,90,190,95,110};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"42","10","O","t","y","p","g","B","96","H","5","v","P","52","25","96","b","L","Y","z","d","52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5","S","Z","D","2","A","W","k","84","44","96","96","y","M"};
    vector<string> st1 = {"(Uvt,Rqa)","(Qync,Kqjl)","(Fayxe,Upn)","(Maeb,Xaq)","(Pmbz,Vje)","(Hnc,Dma)","(Pwsuo,Gyhh)","(Gyhh,Aasipa)","(Fzoe,Lcp)","(Mgs,Vhdmab)","(Qync,Rgd)","(Gql,Liyd)","(Gyhh,Tkbn)","(Arrugl,Adlue)","(Wbcxi,Slfwyo)","(Yzwm,Vqnjg)","(Lnow,Vhdmab)","(Lvaaz,Rttg)","(Nfimij,Iggrg)","(Vje,Lqrmqh)","(Jylbla,Ljkzhs)","(Jnij,Mlo)","(Adlue,Zqiqe)","(Qync,Rttg)","(Gsiiyo,Vxs)","(Xxcl,Fzoe)","(Dbufek,Xaq)","(Ccqunq,Qszsny)","(Zmeop,Mork)","(Qync,Ngi)","(Zboes,Rmlbnj)","(Yldu,Jxv)","(Padz,Gsiiyo)","(Oip,Utc)","(Tal,Pxzfjg)","(Adlue,Zpm)","(Bbcpth,Mork)","(Qync,Lvaaz)","(Pmbz,Qync)","(Alqw,Ngi)","(Bcs,Maeb)","(Rgbu,Zmeop)"};
    Solution s;
    s.bestSeqAtIndex(v1,v3);
    printv(v1);
    v1.resize(3);
    printv(v1);
    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    t1->left = t2;
    t2->right = t3;
    t3->left = t4;
    t3->right = t5;


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