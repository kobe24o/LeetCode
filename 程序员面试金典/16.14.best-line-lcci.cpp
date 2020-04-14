class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
    	int i, j, g, dx, dy, maxCount = 0, n = points.size();
    	double k, b;
    	unordered_map<double,unordered_map<double,set<int>>> m;//k,b,points
    	unordered_map<double,set<int>> v;//x轴截距，斜率不存在时的集合
        vector<set<int>> ans;
    	for(i = 0; i < n-1; ++i)
    	{
    		for(j = i+1; j < n; ++j)
    		{
    			dx = points[j][0]-points[i][0];
    			dy = points[j][1]-points[i][1];
    			if(dx==0)//斜率不存在
    			{
    				if(v[double(points[i][0])].empty())
    					v[double(points[i][0])].insert(i);
    				v[double(points[i][0])].insert(j);
    			}
    			else
    			{
    				k = double(dy)/dx;
    				b = double(points[i][1])-points[i][0]*k;
    				if(m[k][b].empty())
    					m[k][b].insert(i);
    				m[k][b].insert(j);
    			}
    		}
    	}
    	for(auto& mi : m)
    	{
    		for(auto& mii : mi.second)
    		{
                if(mii.second.size() > maxCount)
                {
                    maxCount = mii.second.size();
                    ans.clear();
                    ans.push_back(mii.second);
                }
                else if(mii.second.size() == maxCount)
                    ans.push_back(mii.second);
    		}
    	}
    	for(auto& vi : v)
    	{
    		if(vi.second.size() > maxCount)
			{
				maxCount = vi.second.size();
                ans.clear();
				ans.push_back(vi.second);
			}
            else if(vi.second.size() == maxCount)
                ans.push_back(vi.second);

    	}
        sort(ans.begin(),ans.end(),[&](auto a, auto b){
            auto it1 = a.begin(), it2 = b.begin();
            if(*it1 == *it2)
                return *(++it1) < *(++it2);
            return *it1 < *it2;
        });
        auto it = ans[0].begin();
    	return {*it,*(++it)};
    }
};