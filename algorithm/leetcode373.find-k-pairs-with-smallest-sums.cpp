struct cmp
{
	bool operator()(vector<int>& a, vector<int>& b)
	{
		return a[0] > b[0];//小顶堆
	}
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	int i1 = 0, i2 = 0, n1 = nums1.size(), n2 = nums2.size();
    	if(k > n1*n2) k = n1*n2;
    	if(n1==0 || n2==0) return {};
    	priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    	q.push({nums1[0]+nums2[0],0,0});//sum,i1,i2
    	vector<vector<int>> ans;
        vector<vector<bool>> visited(n1,vector<bool>(n2,false));
        visited[0][0] = true;
    	while(k--)
    	{
    		i1 = q.top()[1];
    		i2 = q.top()[2];
    		ans.push_back({nums1[i1],nums2[i2]});
    		q.pop();
    		if(i1+1 < n1 && !visited[i1+1][i2])
    		{
                q.push({nums1[i1+1]+nums2[i2],i1+1,i2});
                visited[i1+1][i2] = true;
            }
    		if(i2+1 < n2 && !visited[i1][i2+1])
    		{
                q.push({nums1[i1]+nums2[i2+1],i1,i2+1});
                visited[i1][i2+1] = true;
            }
    	}
    	return ans;
    }
};