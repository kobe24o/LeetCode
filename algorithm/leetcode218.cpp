class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    	vector<vector<int>> ans;
    	if(buildings.size() == 0) return ans;
    	multiset<vector<int>> corner;
    	multiset<int> h;
    	h.insert(0);//有空隙的时候方便处理
    	//把建筑物分为上面左右两个顶点
    	for(auto& bd : buildings)
    	{
    		corner.insert({bd[0], -bd[2]});//左边高度取负号区分
    		corner.insert({bd[1], bd[2]});
    	}
    	//multiset自动按第一个元素排序，相同按第二个
    	vector<int> prev(2,0);//前一个拐角
    	for(auto& cn : corner)
    	{
    		if(cn[1] < 0)//左端点,插入
    			h.insert(-cn[1]);
    		else
    			h.erase(h.find(cn[1]));//右端点删除
    		int maxh = *h.rbegin();
    		if(maxh != prev[1])//高度不相等,遇到拐角
    		{
    			prev[0] = cn[0];
    			prev[1] = maxh;
    			ans.push_back(prev);
    		}
    	}
    	return ans;
    }
};