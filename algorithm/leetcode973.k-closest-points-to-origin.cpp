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