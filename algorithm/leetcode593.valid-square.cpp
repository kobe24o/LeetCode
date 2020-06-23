class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<vector<int>> s;
    	vector<vector<int>> p = {p1,p2,p3,p4};
    	vector<vector<int>> vec;
        for(auto& pi : p)
            s.insert(pi);
        if(s.size() < 4) return false;//有重合点
    	int dx, dy, dis;
    	for(int i = 0, j; i < 3; ++i)
    		for(j = i+1; j < 4; ++j)
    		{
    			dx = p[i][0]-p[j][0];
    			dy = p[i][1]-p[j][1];
    			vec.push_back({dx,dy});
    		}
		sort(vec.begin(), vec.end(),[&](auto a, auto b){
			return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
		});
		int dis1 = vec[4][0]*vec[4][0]+vec[4][1]*vec[4][1];
		int dis2 = vec[5][0]*vec[5][0]+vec[5][1]*vec[5][1];
		return (dis1==dis2) && (vec[4][0]*vec[5][0]+vec[4][1]*vec[5][1]==0);
    }	
};