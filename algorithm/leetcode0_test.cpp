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
    int sum = 0;
    vector<int> temp;
public:
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        temp.resize(nums.size());
        return sum;
    }

    void mergesort(vector<int>& arr, int l ,int r)
    {
        if(l >= r)
            return;
        int mid = l + ((r-l)>>1);
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

    void merge(vector<int>& arr, int l, int mid, int r)
    {
        int i = l, j = mid+1, k = 0;
        //方法1：后半部出队，sum+前半部 没有出来的个数(比后面大的)
        while(i <= mid && j <= r)
        {
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
            {
                temp[k++] = arr[j++];
                sum += mid-i+1;
            }
        }
        while(i <= mid)//后面都出完了，前半部还剩一些
            temp[k++] = arr[i++];
        while(j <= r)
            temp[k++] = arr[j++];
        for(i = l,j = 0; j < k; )
            arr[i++] = temp[j++];

        //方法2：前半部出队，sum+ 后半部 已经出队的数量(比前面的小)
        // while(i <= mid && j <= r)
        // {
        // 	if(arr[i] <= arr[j])
        // 	{
        // 		temp[k++] = arr[i++];
        // 		sum += j-(mid+1);
        // 	}
        // 	else
        // 		temp[k++] = arr[j++];
        // }
        // while(i <= mid)//后面都出完了，前半部还剩一些，还需要操作
        // {
        // 	temp[k++] = arr[i++];
        // 	sum += j-(mid+1);
        // }
        // while(j <= r)
        // 	temp[k++] = arr[j++];
        // for(i = l,j = 0; i < k; )
        // 	arr[i++] = temp[j++];
    }
};

int main() {
    vector<vector<int>> v = {{1,3,2},{4,6,5},{7,9,8},{13,15,14},{10,12,11}};
    vector<int> v1 = {7,5,6,4};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{3,7,8},{9,11,13},{15,16,17}};

    Solution s;
    s.reversePairs(v1);

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    t2->left = t1;
    t2->right = t3;
    t3->right = t4;


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