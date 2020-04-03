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
    unordered_map<string,string> father;//并查集
    unordered_map<string,int> m;//名称，频次
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        string name, name1, name2, p;
        int i, count;
        for(string& n : names)
        {
            i = n.find("(");
            name = n.substr(0,i);
            count = 0;
            while(++i < n.size()-1)
                count = 10*count+n[i]-'0';
            m[name] = count;//获取每个名字的次数
            father[name] = name;//并查集初始化
        }
        for(auto& n : synonyms)
        {   //这里可能有上面不存在的name，再添加一遍
            i = n.find(",");
            name1 = n.substr(1,i-1);
            name2 = n.substr(i+1,n.size()-i-2);
            father[name1] = name1;//并查集初始化
            father[name2] = name2;//并查集初始化
        }
        for(auto& n : synonyms)
        {
            i = n.find(",");
            name1 = n.substr(1,i-1);
            name2 = n.substr(i+1,n.size()-i-2);
            merge(name1,name2);//全部进行合并和路径压缩
        }
        unordered_map<string,vector<string>> fatherSet;
        for(auto f : father)
        {
            name = f.first;
            p = uniFind(name);
            fatherSet[p].push_back(name);
        }
        vector<string> ans;
        for(auto& f : fatherSet)
        {
            count = 0;
            for(auto& v : f.second)
            {
                count += m[v];
            }
            ans.push_back(f.first+"("+to_string(count)+")");
        }
        return ans;
    }

    string uniFind(string x)
    {
        if(x == father[x])
            return x;
        return father[x] = uniFind(father[x]);//等式为路径压缩操作
    }

    void merge(string x, string y)
    {
        string fatherx = uniFind(x);
        string fathery = uniFind(y);
        if(fatherx != fathery)
        {
            if(fatherx < fathery)
                swap(fatherx, fathery);//x的字典序大
            father[fatherx] = fathery;//字典序小的y做代表
        }
    }
};

//["01","10","0","1","1001010"] 9
//["01","0","0101010"]  6
//["011000","0111010","01101010"] 9
//["011000","0111011","01001010"] 11
//["01","1000000","11111111"] 13
//则当前节点所构成的最大距离即左深度+右深度-2*当前节点深度。

//["...1","..S.","..*.",".0.T"]   9
void printv(vector<string>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<char>> v4 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<int> v1 = {1,2,3,3,4,3,4,5,6};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"Pwsuo(71)","Prf(48)","Rgbu(49)","Zvzm(31)","Xxcl(25)","Bbcpth(42)","Padz(70)","Jmqqsj(19)","Uwy(26)","Jylbla(65)","Xioal(11)","Npbu(62)","Jpftyg(96)","Tal(46)","Hnc(100)","Yldu(85)","Alqw(45)","Wbcxi(34)","Kxjw(36)","Clplqf(8)","Fayxe(66)","Slfwyo(48)","Xbesji(70)","Pmbz(22)","Oip(2)","Fzoe(63)","Qync(79)","Utc(11)","Sqwejn(19)","Ngi(8)","Gsiiyo(60)","Bcs(73)","Icsvku(1)","Yzwm(92)","Vaakt(21)","Uvt(70)","Axaqkm(100)","Gyhh(84)","Gaoo(98)","Ghlj(35)","Umt(13)","Nfimij(52)","Zmeop(77)","Vje(29)","Rqa(47)","Upn(89)","Zhc(44)","Slh(66)","Orpqim(69)","Vxs(85)","Gql(19)","Sfjdjc(62)","Ccqunq(93)","Oyo(32)","Bvnkk(52)","Pxzfjg(45)","Kaaht(28)","Arrugl(57)","Vqnjg(50)","Dbufek(63)","Fshi(62)","Lvaaz(63)","Phlto(41)","Lnow(70)","Mqgga(31)","Adlue(82)","Zqiqe(27)","Mgs(46)","Zboes(56)","Dma(70)","Jnij(57)","Ghk(14)","Mrqlne(39)","Ljkzhs(35)","Rmlbnj(42)","Qszsny(93)","Aasipa(26)","Wzt(41)","Xuzubb(90)","Maeb(56)","Mlo(18)","Rttg(4)","Kmrev(31)","Kqjl(39)","Iggrg(47)","Mork(88)","Lwyfn(50)","Lcp(42)","Zpm(5)","Qlvglt(36)","Liyd(48)","Jxv(67)","Xaq(70)","Tkbn(81)","Rgd(85)","Ttj(28)","Ndc(62)","Bjfkzo(54)","Lqrmqh(50)","Vhdmab(41)"};
    vector<string> st1 = {"(Uvt,Rqa)","(Qync,Kqjl)","(Fayxe,Upn)","(Maeb,Xaq)","(Pmbz,Vje)","(Hnc,Dma)","(Pwsuo,Gyhh)","(Gyhh,Aasipa)","(Fzoe,Lcp)","(Mgs,Vhdmab)","(Qync,Rgd)","(Gql,Liyd)","(Gyhh,Tkbn)","(Arrugl,Adlue)","(Wbcxi,Slfwyo)","(Yzwm,Vqnjg)","(Lnow,Vhdmab)","(Lvaaz,Rttg)","(Nfimij,Iggrg)","(Vje,Lqrmqh)","(Jylbla,Ljkzhs)","(Jnij,Mlo)","(Adlue,Zqiqe)","(Qync,Rttg)","(Gsiiyo,Vxs)","(Xxcl,Fzoe)","(Dbufek,Xaq)","(Ccqunq,Qszsny)","(Zmeop,Mork)","(Qync,Ngi)","(Zboes,Rmlbnj)","(Yldu,Jxv)","(Padz,Gsiiyo)","(Oip,Utc)","(Tal,Pxzfjg)","(Adlue,Zpm)","(Bbcpth,Mork)","(Qync,Lvaaz)","(Pmbz,Qync)","(Alqw,Ngi)","(Bcs,Maeb)","(Rgbu,Zmeop)"};
    Solution s;
    vector<string>ans = s.trulyMostPopular(st,st1);
    sort(ans.begin(), ans.end());
    vector<string> v5 = {"Prf(48)","Zvzm(31)","Jmqqsj(19)","Uwy(26)","Jylbla(100)","Xioal(11)","Npbu(62)","Jpftyg(96)","Pxzfjg(91)","Dma(170)","Jxv(152)","Kxjw(36)","Clplqf(8)","Slfwyo(82)","Xbesji(70)","Fzoe(130)","Alqw(424)","Oip(13)","Sqwejn(19)","Icsvku(1)","Vqnjg(142)","Vaakt(21)","Rqa(117)","Axaqkm(100)","Aasipa(262)","Gaoo(98)","Ghlj(35)","Umt(13)","Iggrg(99)","Fayxe(155)","Zhc(44)","Slh(66)","Orpqim(69)","Gsiiyo(215)","Sfjdjc(62)","Ccqunq(186)","Oyo(32)","Bvnkk(52)","Kaaht(28)","Fshi(62)","Phlto(41)","Mqgga(31)","Adlue(171)","Lnow(157)","Rmlbnj(98)","Jnij(75)","Ghk(14)","Mrqlne(39)","Wzt(41)","Xuzubb(90)","Kmrev(31)","Bbcpth(256)","Lwyfn(50)","Qlvglt(36)","Gql(67)","Bcs(262)","Ttj(28)","Ndc(62)","Bjfkzo(54)"};
    sort(v5.begin(), v5.end());
    printv(ans);
    printv(v5);
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