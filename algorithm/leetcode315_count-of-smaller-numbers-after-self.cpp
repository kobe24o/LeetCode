// class Node	//树的节点
// {
// public:
// 	int val;
// 	int count;//小于该节点的个数
// 	Node *left, *right;
// 	Node(int v): val(v), count(0), left(NULL), right(NULL){}
// };
// class BST
// {
// 	Node *root;
// public:
// 	BST():root(NULL){}
// 	int insert(int n)
// 	{
// 		return insert(n, root);
// 	}
// private:
// 	int insert(int n, Node* &cur)//指针的引用，将节点之间连起来
// 	{
// 		if(!cur)
// 		{
// 			cur = new Node(n);//创建的新节点cur更新至调用处的参数
// 			return 0;//自己等于自己，不用加，返回0
// 		}
// 		else
// 		{
// 			if(n > cur->val)
// 				//我比当前大，+1，还要 +之前记录的比它小的个数，+它右侧的
// 				return 1 + cur->count + insert(n,cur->right);
// 			if(n < cur->val)
// 			{	//我比当前小
// 				cur->count++;	//比当前小的记录 +1
// 				return insert(n,cur->left);//去左边子树里查找
// 			}
// 			else// ==，+比当前小的个数，+右侧里面的
// 				return cur->count + insert(n,cur->right);
// 		}
// 	}
// };
// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int> ans(nums.size());
//         BST tree;
//         for(int i = nums.size()-1; i >= 0; --i)
//         	ans[i] = tree.insert(nums[i]);
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         if(nums.empty())
//         	return {};
//         vector<int> ans, sorted;
//         int pos;
//         vector<int>::iterator it;
//         for(int i = nums.size()-1; i >= 0; --i)
//         {
//         	pos = binaryInsert(sorted,nums[i]);
//         	it = sorted.begin()+pos;
//         	sorted.insert(it,nums[i]);
//         	ans.push_back(pos);
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
//     int binaryInsert(vector<int>& sorted, int num)
//     {
//     	int left = 0, right = sorted.size()-1, mid;
//     	while(left <= right)
//     	{
//     		mid = left+((right-left)>>1);
//     		if(sorted[mid] < num)
//     			left = mid+1;
//     		else if(sorted[mid] >= num)
//     			right = mid-1;
//     	}
//     	return left;//自己在纸上测试下，只能是left
//     }
// };

#include <vector>
using namespace std;
class Solution {
	vector<int> ans;//存储结果
	vector<int> temp;//归并排序临时空间
	vector<int> idx;//归并排序的对象，排的是---下标，不是数值
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty())
        	return {};
        ans.resize(nums.size());
        temp.resize(nums.size());
        idx.resize(nums.size());
        for(int i = 0; i < nums.size(); ++i)
        {
        	idx[i] = i;
        	ans[i] = 0;
        }
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }

    void mergeSort(vector<int> &nums, int l, int r)
    {
    	if(l == r)
    		return;
    	int mid = l+((r-l)>>1);
    	mergeSort(nums,l,mid);
    	mergeSort(nums,mid+1,r);
    	merge(nums,l,mid,r);
    }
    void merge(vector<int>& nums, int l, int mid, int r)
    {
    	int i = l, j = mid+1, k = l;
    	while(i <= mid && j <= r)
    	{
    		if(nums[idx[i]] <= nums[idx[j]])
    		{
    			ans[idx[i]] += j-(mid+1);
    			temp[k++] = idx[i++];
    		}
    		else
    		{
    			temp[k++] = idx[j++];
    			// ans[idx[i]] += j-mid;
    		}
    	}
    	while(i <= mid)
    	{
    		ans[idx[i]] += j-(mid+1);
			temp[k++] = idx[i++];
    	}
    	while(j <= r)
    	{
    		temp[k++] = nums[j++];
    		// ans[idx[i]] += j-mid;
		}
    	for(i = l; i <= r; ++i)
    		idx[i] = temp[i];
    }
};
int main()
{
	Solution s;
	vector<int> v = {1,2,7,8,5};
	s.countSmaller(v);
}