class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
    	vector<int> ans(mat[0]);
    	int i, j, ki;
    	for(i = 1; i < mat.size(); ++i)
    	{
    		multiset<int> s;
    		for(j = 0; j < mat[i].size(); ++j)
    		{
    			for(ki = 0; ki < ans.size(); ++ki)
    				s.insert(mat[i][j]+ans[ki]);
    		}
    		ans.assign(s.begin(),s.end());
    		ans.resize(min(k, int(ans.size())));
    	}
    	return ans[k-1];
    }
};


struct cmp
{
	bool operator()(const pair<int,vector<int>>& a, const pair<int,vector<int>>& b) const
	{
		return a.first > b.first;//小顶堆，和小的在堆顶
	}
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
    	pair<int,vector<int>> tp;
    	int i, j, s0 = 0, m = mat.size(), n = mat[0].size(), s;
    	for(i = 0; i < m; ++i)
    		s0 += mat[i][0];//最小的和
    	vector<int> idx(m,0);//每行选取的下标
    	vector<int> tempidx;
    	priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>,cmp> q;
		q.push({s0,idx});
		set<vector<int>> visited;
		visited.insert(idx);//访问过了
		while(--k)
		{
			tp = q.top();
			s0 = tp.first;
			idx = tp.second;
			q.pop();
			for(i = 0; i < m; ++i)
			{
				tempidx = idx;
				tempidx[i]++;
				if(tempidx[i] < n && !visited.count(tempidx))//没有访问过该状态
				{
					s = s0-mat[i][idx[i]]+mat[i][idx[i]+1];
					visited.insert(tempidx);
					q.push({s,tempidx});
				}
			}
		}
		return q.top().first;
    }
};