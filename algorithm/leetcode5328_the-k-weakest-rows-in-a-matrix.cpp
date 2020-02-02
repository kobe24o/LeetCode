class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int i, j, count;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(i = 0; i < mat.size(); i++)
        {
        	count = 0;
        	for(j = 0; j < mat[i].size(); j++)
        	{
        		if(mat[i][j])
        			count++;
        	}
        	q.push({count, i});
        }
        vector<int> ans;
        while(k--)
        {
        	ans.push_back(q.top().second);
        	q.pop();
        }
        return ans;
    }
};