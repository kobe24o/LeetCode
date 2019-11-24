class Solution {
	unordered_map<int,int> m;
	vector<int> ans;
	int maxCount = 0;
	int l, r, s;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sumof(root);
        for(auto& mi : m)
        	if(mi.second == maxCount)
        		ans.push_back(mi.first);
        return ans;
    }

    int sumof(TreeNode* root)
    {
    	if(root == NULL)
    		return 0;
    	l = sumof(root->left);
    	r = sumof(root->right);
    	s = l+r+root->val;
    	if(++m[s] > maxCount)
    		maxCount = m[s];
    	return s;
    }
};