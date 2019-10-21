class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        unordered_map<int,int> m;
        int i, j, dis, ans = 0;
        for(i = 0; i < p.size(); ++i)
        {
        	m.clear();//以i为顶点的
        	for(j = 0; j < p.size(); ++j)
        		if(i != j)
        		{
        			dis = pow(p[i][0]-p[j][0],2)+pow(p[i][1]-p[j][1],2);
        			m[dis]++;
                }
	        for(auto it = m.begin(); it != m.end(); ++it)
	        	ans += it->second*(it->second-1);    
        }
        return ans;
    }
};