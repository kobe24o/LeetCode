class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    	if(K == points.size())
    		return points;
    	sort(points.begin(),points.end(),[&](auto a, auto b){
    		return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
    	});
    	return vector<vector<int>>(points.begin(),points.begin()+K);
    }
};

struct cmp{
	bool operator()(const vector<int>& a, const vector<int>& b)const
	{
		return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];//大顶堆
	}
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    	if(K == points.size())
    		return points;
    	priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    	for(int i = 0; i < points.size(); ++i)
    	{
    		if(q.size() < K)
    			q.push(points[i]);
    		else if(q.top()[0]*q.top()[0]+q.top()[1]*q.top()[1] > 
    					points[i][0]*points[i][0]+points[i][1]*points[i][1])
    		{
    			q.pop();
    			q.push(points[i]);
    		}
    	}
    	vector<vector<int>> ans(q.size());
    	int i = 0;
    	while(!q.empty())
    	{
    		ans[i++] = q.top();
    		q.pop();
    	}
    	return ans;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    	if(K == points.size())
    		return points;
    	findkth(points,0,points.size()-1,K);
    	points.resize(K);
        return points;
    }
    int dis(vector<vector<int>>& points, int i)
    {
        return points[i][0]*points[i][0]+points[i][1]*points[i][1];
    }
    void findkth(vector<vector<int>>& points,int l, int r, int K)
    {
        int i = l, j = r, p = dis(points, l);
        while(i < j)
        {
            while(i < j && dis(points,j) > p)
                j--;
            while(i < j && dis(points,i) <= p)
                i++;
            swap(points[i], points[j]);
        }
        swap(points[l], points[i]);
        if(i < K)//左边都是答案的一部分，取右边找
            findkth(points,i+1,r,K);
        else if(i > K)//左边多于K个，在左边继续分割
            findkth(points,l,i-1,K);
        else
            return;
    }
};

