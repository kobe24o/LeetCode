#include<vector>
#include <unordered_map>
using namespace std;

struct TreeNode{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int,int> m, n;
        for(int i = 0; i < pre.size(); ++i)
        	m[pre[i]] = i, n[post[i]] = i;
        return bt(pre,0,pre.size()-1,post,0,post.size()-1,m);
    }

    TreeNode* bt(vector<int>& pre,int preS, int preE,vector<int>& post, int postS, int postE, unordered_map<int,int> &m)
    {
    	if(preS > preE)
    		return NULL;
    	if(preS == preE)
        {
    	    return new TreeNode(pre[preS]);
        }
    	TreeNode *root = new TreeNode(pre[preS]);
    	int leftlen = m[post[postE-1]]-preS-1;
    	int rightlen = preE-m[post[postE-1]]+1;
    	root->left = bt(pre,preS+1,preS+leftlen,post,postS,postS+leftlen-1,m);
    	root->right = bt(pre,m[post[postE-1]],preE,post,postE-rightlen,postE-1,m);
    	return root;
    }
};
int main()
{
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> post = {4,5,2,6,7,3,1};
    Solution s;
    s.constructFromPrePost(pre,post);
}
