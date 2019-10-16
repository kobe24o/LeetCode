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
	void MaxXor(Node *p2, Node *p1, int j, int &ans)
	{
		if(j == -1)
			return;
		int ans1 = 0, ans2 = 0, ans3 = 0, init = ans;
		if((p2->next[0] && p1->next[1])||(p2->next[1] && p1->next[0]))
		{
			if(p2->next[0] && p1->next[1])
			{
				ans += (1<<j);
				MaxXor(p2->next[0], p1->next[1],j-1,ans);
				ans1 = ans;
			}
			if(p2->next[1] && p1->next[0])
			{
				ans = init;
				ans += (1<<j);
				MaxXor(p2->next[1], p1->next[0],j-1,ans);
				ans2 = ans;
			}
		}
		else
		{
			if(p2->next[0] && p1->next[0])
			{
				ans = init;
				MaxXor(p2->next[0], p1->next[0],j-1,ans);
				ans3 = ans;
			}
			if(p2->next[1] && p1->next[1])
			{
				ans = init;
				MaxXor(p2->next[1], p1->next[1],j-1,ans);
			}
		}
		if(ans1>ans)	ans = ans1;
		if(ans2>ans)	ans = ans2;
		if(ans3>ans)	ans = ans3;
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
        while(j >= 0 && (!cur->next[0] || !cur->next[1]))
        {
        	if(cur->next[0])
        		cur = cur->next[0];
        	else
        		cur = cur->next[1];
        	j--;
        }//找到cur是左右都有的
        if(j >= 0)
        {
		    ans += (1<<j);
            tree.MaxXor(cur->next[0],cur->next[1],j-1,ans);
        }
        return ans;
    }
};
int main()
{
	vector<int> vec = {0};
	Solution s;
	cout << s.findMaximumXOR(vec);
	return 0;
}

struct Node
{
    Node* next[2] = {NULL};
};
class Solution 
{
public:
    void insert(int n, Node* root)
    {
    	int bit;
        for (int i = 31; i >= 0; --i) 
        {
            bit = (n >> i) & 1;
            if (!root->next[bit])
                root->next[bit] = new Node();
            root = root->next[t];
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        for (int n : nums)
            insert(n, root);
        int ans = 0, tmp = 0;
        Node* p = root;
        for (auto val : nums) {
            p = root; tmp = 0;
            for (int i = 30; i >= 0; --i) {
                int t = (val >> i) & 1;
                if (p->next[!t]) {
                    p = p->next[!t];
                    tmp += (1 << i);
                }else p = p->next[t];
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};