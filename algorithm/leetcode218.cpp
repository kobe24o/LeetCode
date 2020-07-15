struct cmp
{
	bool operator()(const vector<int>& a, const vector<int>& b) const
	{
		if(a[1] == b[1])
			return a[2] < b[2];
		return a[1] > b[1];
	}
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    	vector<vector<int>> ans;
    	priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    }
};