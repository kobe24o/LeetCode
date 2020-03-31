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

class Solution {	//桶排序
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
            return arr;
        int i, j = 0, min, max;
        min = max = arr[0];
        for(i = 1; i < arr.size(); ++i)
        {
            min = arr[i] < min ? arr[i] : min;
            max = arr[i] > max ? arr[i] : max;
        }
        if(min == max)
            return arr;
        int div = 5;//桶个数
        int space = (max-min)/div+1;
        vector<int> temp(arr.size());
        vector<int> bucketsize(div,0);
        vector<int> bucketPos(div,0);
        for(i = 0; i < arr.size(); ++i)
            bucketsize[(arr[i]-min)/space]++;
        bucketPos[0] = bucketsize[0];
        for(i = 1; i < arr.size(); ++i)
            bucketPos[i] += bucketPos[i-1] + bucketsize[i];//桶结束位置的下一个
        for(i = 0; i < arr.size(); ++i)
            temp[--bucketPos[(arr[i]-min)/space]] = arr[i];
        for(i = 0; i < div; ++i)
        {
            if(bucketsize[i] > 1)
            {
                qsort(temp,bucketPos[i],bucketPos[i]+bucketsize[i]-1);
            }
        }
        for(i = 0; i < arr.size(); ++i)
            arr[i] = temp[i];
        return arr;
    }

    void qsort(vector<int>& arr, int l, int r)
    {
        if(l >= r)
            return;
        int Pl = l, Pr = l;
        partition(arr,l,r,Pl,Pr);
        qsort(arr,l,Pl-1);
        qsort(arr,Pr+1,r);
    }

    void partition(vector<int>& arr, int l, int r, int& Pl, int& Pr)
    {
        selectMid(arr,l,r);
        int P = arr[l];
        int i = l, j = r;
        while(i < j)
        {
            while(i < j && P < arr[j])//没有等于号，哨兵都在左侧
                j--;
            swap(arr[i], arr[j]);
            while(i < j && arr[i] <= P)
                i++;
            swap(arr[i], arr[j]);
        }
        Pl = Pr = i;
        for(i = i-1; i >= l; --i)
        {
            if(arr[i] == P)
            {
                Pl--;
                swap(arr[i], arr[Pl]);
            }
        }
    }

    void selectMid(vector<int>& arr, int l, int r)
    {
        int mid = l+((r-l)>>1);
        if(arr[mid] > arr[r])
            swap(arr[mid],arr[r]);
        if(arr[l] > arr[r])
            swap(arr[l], arr[r]);
        if(arr[mid] > arr[l])
            swap(arr[mid], arr[l]);
    }
};

//["01","10","0","1","1001010"] 9
//["01","0","0101010"]  6
//["011000","0111010","01101010"] 9
//["011000","0111011","01001010"] 11
//["01","1000000","11111111"] 13
//则当前节点所构成的最大距离即左深度+右深度-2*当前节点深度。

//["...1","..S.","..*.",".0.T"]   9

int main() {
    vector<vector<char>> v4 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<int> v1 = {1,2,3,3,4,3,4,5,6};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,4,3},{6,5,2}};
    vector<string> st  = { };
    Solution s;
    s.sortArray(v1);

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