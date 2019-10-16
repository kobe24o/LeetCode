#include<vector>
#include<iostream>
using namespace std;
// class Node
// {
// public:
// 	int val;
// 	Node *next[2];
// 	Node(int v = 0):val(v) {next[0] = next[1] = NULL;}
// };
// class Trie
// {
// public:
// 	Node *root;
// 	Trie()
// 	{
// 		root = new Node();
// 	}
// 	~Trie()//析构释放内存
// 	{
// 		destroy(root);
// 	}
// 	void destroy(Node *root)
// 	{
// 		if(root == NULL)
// 			return;
// 		destroy(root->next[0]);
// 		destroy(root->next[1]);
// 		delete root;
// 	}
// 	void insert(int n)//插入数字的二进制位
// 	{
// 		Node *cur = root;
// 		int bit;
// 		for(int i = 31; i >= 0; --i)
// 		{
// 			bit = (n>>i) & 1;
// 			if(cur->next[bit] == NULL)
// 				cur->next[bit] = new Node(bit);
// 			cur = cur->next[bit];
// 		}
// 	}
// 	int MaxXOR(int n)
// 	{
// 		Node *cur = root;
// 		int val = 0, bit, anotherBit;
// 		for(int i = 31; i >= 0; --i)
// 		{
// 			bit = (n>>i) & 1;
// 			anotherBit = bit^1;//取反
// 			if(cur->next[anotherBit])
// 			{
// 				val += (1<<i);
// 				cur = cur->next[anotherBit];
// 			}
// 			else
// 				cur = cur->next[bit];
// 		}
// 		return val;
// 	}
// };
// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         Trie tree;
//         int ans = INT_MIN;
//         for(int n:nums)
//         	tree.insert(n);
//         for(int n:nums)
//         	ans = max(ans,tree.MaxXOR(n)); 
//         return ans;
//     }
// };

class Node
{
public:
	int val;
	Node *next[2];
	Node(int v = 0):val(v) {next[0] = next[1] = NULL;}
};
class Trie
{
public:
	Node *root;
	Trie()
	{
		root = new Node();
	}
	~Trie()//析构释放内存
	{
		destroy(root);
	}
	void destroy(Node *root)
	{
		if(root == NULL)
			return;
		destroy(root->next[0]);
		destroy(root->next[1]);
		delete root;
	}
	void insert(int n)//插入数字的二进制位
	{
		Node *cur = root;
		int bit;
		for(int i = 31; i >= 0; --i)
		{
			bit = (n>>i) & 1;
			if(cur->next[bit] == NULL)
				cur->next[bit] = new Node(bit);
			cur = cur->next[bit];
		}
	}
	int MaxXor(Node *zero, Node *one, int j, int ans)
	{
		if(j == -1)
			return 0;
		if(zero && one)
			ans += (1<<j);
		if(one->next[0] == NULL)
		{
			if(zero->next[0] != NULL)
				return ans+MaxXor(one->next[1],zero->next[0],j-1,ans);
			return ans+MaxXor(one->next[1],zero->next[1],j-1,ans);
		}
		if(one->next[1] == NULL)
		{
			if(zero->next[1] != NULL)
				return ans+MaxXor(one->next[0],zero->next[1],j-1,ans);
			return ans+MaxXor(one->next[0],zero->next[0],j-1,ans);
		}
		if(zero->next[0] == NULL)
		{
			if(one->next[0] != NULL)
				return ans+MaxXor(one->next[0],zero->next[1],j-1,ans);
			return ans+MaxXor(one->next[1],zero->next[1],j-1,ans);
		}
		if(zero->next[1] == NULL)
		{
			if(one->next[1] != NULL)
				return ans+MaxXor(one->next[1],zero->next[0],j-1,ans);
			return ans+MaxXor(one->next[0],zero->next[0],j-1,ans);
		}
        int a = ans+MaxXor(one->next[1],zero->next[0],j-1,ans), b = ans+MaxXor(one->next[0],zero->next[1],j-1,ans);
		return max(a,b);
	}
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie tree;
        for(int n:nums)
        	tree.insert(n);
        Node *cur = tree.root;
        int j = 31, ans = 0;
        while(!cur->next[0] || !cur->next[1])
        {
        	if(cur->next[0])
        		cur = cur->next[0];
        	else
        		cur = cur->next[1];
        	j--;
        }//找到cur是左右都有的
        tree.MaxXor(cur->next[0],cur->next[1],j,ans);
        return ans;
    }
};
int main()
{
	vector<int> vec = {3,10,5,25,2,8};
	Solution s;
	cout << s.findMaximumXOR(vec);
	return 0;
}