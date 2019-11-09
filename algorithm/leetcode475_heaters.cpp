class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        //为处理边界方便增加两个虚拟无穷远加热站
        heaters.push_back(INT_MAX);
        heaters.push_back(-1e10);
        sort(heaters.begin(),heaters.end());
        int i = 0, j = 0, r = 0;
        while(i < houses.size())
        {
        	if(houses[i] >= heaters[j] && houses[i] <= heaters[j+1])
        	{
        		r = max(r,min(house[i]-heaters[j], heaters[j+1]-houses[i]));
        		++i;
        	}
        	else
        		++j;
        }
        return r;
    }
};