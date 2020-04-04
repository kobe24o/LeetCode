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
    vector<string> findLongestSubarray(vector<string>& array) {
        if(array.size() < 2)
            return {};
        map<int, pair<int,int>> m;
        int sum = 0;
        for(int i = 0; i < array.size(); ++i)
        {
            if(isdigit(array[i][0]))
                sum++;
            else
                sum--;
            if(!m.count(sum))
            {
                m[sum].first = i;
                m[sum].second = -1;
            }
            else if(m[sum].first != -1)
                m[sum].second = i;
        }
        if(sum == 0)
            return array;
        int maxlen = 0;
        vector<int> key;
        for(auto& mi : m)
        {
            if(mi.second.second == -1)
                continue;
            if(mi.second.second-mi.second.first > maxlen)
            {
                maxlen = mi.second.second-mi.second.first;
                key.clear();
                key.push_back(mi.first);
            }
            else if(mi.second.second-mi.second.first == maxlen)
                key.push_back(mi.first);
        }
        string minidx = "zzzzzzzzzzzz";
        int ansKey;
        for(int k : key)
        {
            if(array[m[k].first] < minidx)
            {
                minidx = array[m[k].first];
                ansKey = k;
            }
        }
        return vector<string> (array.begin()+m[ansKey].first, array.begin()+m[ansKey].second);
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
    vector<string> st  = {"42","10","O","t","y","p","g","B","96","H","5","v","P","52","25","96","b","L","Y","z","d","52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5","S","Z","D","2","A","W","k","84","44","96","96","y","M"};
    vector<string> st1 = {"(Uvt,Rqa)","(Qync,Kqjl)","(Fayxe,Upn)","(Maeb,Xaq)","(Pmbz,Vje)","(Hnc,Dma)","(Pwsuo,Gyhh)","(Gyhh,Aasipa)","(Fzoe,Lcp)","(Mgs,Vhdmab)","(Qync,Rgd)","(Gql,Liyd)","(Gyhh,Tkbn)","(Arrugl,Adlue)","(Wbcxi,Slfwyo)","(Yzwm,Vqnjg)","(Lnow,Vhdmab)","(Lvaaz,Rttg)","(Nfimij,Iggrg)","(Vje,Lqrmqh)","(Jylbla,Ljkzhs)","(Jnij,Mlo)","(Adlue,Zqiqe)","(Qync,Rttg)","(Gsiiyo,Vxs)","(Xxcl,Fzoe)","(Dbufek,Xaq)","(Ccqunq,Qszsny)","(Zmeop,Mork)","(Qync,Ngi)","(Zboes,Rmlbnj)","(Yldu,Jxv)","(Padz,Gsiiyo)","(Oip,Utc)","(Tal,Pxzfjg)","(Adlue,Zpm)","(Bbcpth,Mork)","(Qync,Lvaaz)","(Pmbz,Qync)","(Alqw,Ngi)","(Bcs,Maeb)","(Rgbu,Zmeop)"};
    Solution s;
    vector<string>ans = s.findLongestSubarray(st);
//    sort(ans.begin(), ans.end());
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