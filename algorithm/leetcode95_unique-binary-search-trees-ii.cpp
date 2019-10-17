#include<vector>
using namespace std;
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
        	return {};
        return generateTrees(1,n);
    }

    vector<TreeNode*> generateTrees(int start, int end)
    {
    	vector<TreeNode*> ans;
    	if(start > end)
    	{
    		ans.push_back(NULL);
    		return ans;
    	}
    	vector<TreeNode*> subLeft, subRight;
    	TreeNode *node;
    	for(int i = start; i < end; i++)
    	{
    		subLeft = generateTrees(start,i-1);
    		subRight = generateTrees(i+1,end);
    		for(TreeNode* l : subLeft)
    			for(TreeNode* r : subRight)
    			{
    				node = new TreeNode(i);
    				node->left = l;
    				node->right = r;
    				ans.push_back(node);
    			}
    	}
    	return ans;
    }
};
int main()
{
	Solution s;
	s.generateTrees(3);
}