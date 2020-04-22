class Solution {	
    map<int, vector<vector<int>>> m;//x坐标，节点集合< <val, deep> >
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //前序遍历 根左右
        if(!root)
            return {};
        dfs(root,0,0);
        vector<vector<int>> temp;
        vector<vector<int>> ans(m.size());
        int i = 0, j;
        for(auto it  = m.begin(); it != m.end(); ++it)
        {
        	temp = it->second;
        	sort(temp.begin(), temp.end(),[&](auto a, auto b){
        		if(a[1] == b[1])
        			return a[0] < b[0];
        		return a[1] < b[1];
        	});
            for(j = 0; j < temp.size(); ++j)
                ans[i].push_back(temp[j][0]);
            i++;
        }
        return ans;
    }
    void dfs(TreeNode* root, int x, int deep)
    {
        if(!root)
            return;
        m[x].push_back({root->val,deep});
        dfs(root->left, x-1, deep+1);
        dfs(root->right, x+1, deep+1);
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<vector<int>>> m;//x坐标，节点集合< <val, deep> >
        if(!root)
            return {};
        queue<pair<TreeNode*,pair<int,int>>> q;//节点及其坐标x,y
        q.push({root,{0,0}});
        pair<TreeNode*,pair<int,int>> tp;
        TreeNode* node;
        int x, y, size;
        while(!q.empty())
        {
        	size = q.size();
        	while(size--)
        	{
	            tp = q.front();
	            q.pop();
	            node = tp.first;
	            x = tp.second.first;
	            y = tp.second.second;
	            m[x].push_back(vector<int> {node->val,y});
	            if(node->left)
	                q.push({node->left, {x-1,y+1}});
	            if(node->right)
	                q.push({node->right, {x+1,y+1}});
	        }
        }
        vector<vector<int>> temp;
        vector<vector<int>> ans(m.size());
        int i = 0, j;
        for(auto it  = m.begin(); it != m.end(); ++it)
        {
        	temp = it->second;
        	sort(temp.begin(), temp.end(),[&](auto a, auto b){
        		if(a[1] == b[1])
        			return a[0] < b[0];
        		return a[1] < b[1];
        	});
            for(j = 0; j < temp.size(); ++j)
                ans[i].push_back(temp[j][0]);
            i++;
        }
        return ans;
    }
};