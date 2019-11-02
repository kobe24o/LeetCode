class Node	//树的节点
{
public:
	int val;
	int count;//小于该节点的个数
	Node *left, *right;
	Node(int v): val(v), count(0), left(NULL), right(NULL){}
};
class BST
{
	Node *root;
public:
	BST():root(NULL){}
	int insert(int n)
	{
		return insert(n, root);
	}
private:
	int insert(int n, Node* &cur)//指针的引用，将节点之间连起来
	{
		if(!cur)
		{
			cur = new Node(n);//创建的新节点cur更新至调用处的参数
			return 0;//自己等于自己，不用加，返回0
		}
		else
		{
			if(n > cur->val)
				//我比当前大，+1，还要 +之前记录的比它小的个数，+它右侧的
				return 1 + cur->count + insert(n,cur->right);
			if(n < cur->val)
			{	//我比当前小
				cur->count++;	//比当前小的记录 +1
				return insert(n,cur->left);//去左边子树里查找
			}
			else// ==，+比当前小的个数，+右侧里面的
				return cur->count + insert(n,cur->right);
		}
	}
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        BST tree;
        for(int i = nums.size()-1; i >= 0; --i)
        	ans[i] = tree.insert(nums[i]);
        return ans;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty())
        	return {};
        vector<int> ans, sorted;
        int pos;
        vector<int>::iterator it;
        for(int i = nums.size()-1; i >= 0; --i)
        {
        	pos = binaryInsert(sorted,nums[i]);
        	it = sorted.begin()+pos;
        	sorted.insert(it,nums[i]);
        	ans.push_back(pos);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int binaryInsert(vector<int>& sorted, int num)
    {
    	int left = 0, right = sorted.size()-1, mid;
    	while(left <= right)
    	{
    		mid = left+((right-left)>>1);
    		if(sorted[mid] < num)
    			left = mid+1;
    		else if(sorted[mid] >= num)
    			right = mid-1;
    	}
    	return left;//自己在纸上测试下，只能是left
    }
};