class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    	vector<vector<int>> w_b_dis;
    	for(int i = 0; i < workers.size(); i++)
    	{
    		for(int j = 0; j < bikes.size(); j++)
    		{
    			int distance = dis(workers[i][0], workers[i][1], bikes[j][0], bikes[j][1]);
    			w_b_dis.push_back({distance,i,j});
    		}
    	}
    	sort(w_b_dis.begin(), w_b_dis.end());
    	vector<bool> 
    }
    int dis(int a, int b, int c, int d)
    {
    	return abs(a-c)+abs(b-d);
    }
};