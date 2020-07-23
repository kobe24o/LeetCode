class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),[&](auto a, auto b){
        	if(a[0] == b[0])
        		return a[1] < b[1];//y大的靠后
        	return a[0] < b[0];//按x坐标排序
        });
        if(points[0][0] == points[points.size() - 1][0])//x都相等，在一条线上，true
        	return true;
        points.erase(unique(points.begin(), points.end()), points.end());//有重复的点
        int half = points.size()/2;
        sort(points.begin(), points.begin()+half, [&](auto a, auto b){
        	if(a[0] == b[0])
        		return a[1] > b[1];//前半部分y大的靠前
        	return a[0] < b[0];//按x坐标排序
        });
        int l = 0, r = points.size()-1;
        if(points[l][1] != points[r][1]) return false;
        int xmid = points[l++][0] + points[r--][0];//中心的两倍
        while(l < r)
        {
        	if(points[l][0] != points[r][0] && (points[l][1] != points[r][1] 
        		|| points[l][0] + points[r][0] != xmid)) return false;
            l++,r--;
        }
    	return points[l][0] + points[r][0] == xmid;
    }
};

// [[1,1],[0,1],[-1,1],[0,0]]
// [[1,2],[2,2],[1,4],[2,4]]
// [[-16,1],[16,1],[16,1]]
// [[1,1],[-1,1]]
// [[0,0],[0,-1]]
// [[0,0],[1,0],[3,0]]