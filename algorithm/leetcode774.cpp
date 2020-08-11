class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
    	int n = stations.size();
    	vector<int> dis(n-1);
    	for(int i = 1; i < n; ++i)
    	{
    		dis[i-1] = stations[i]-stations[i-1];//加油站之间的距离
    	}
    	double l = 0, r = 1e8+1, d, ans;
    	while(r-l >= 1e-7)
    	{
    		d = (l+r)/2.0;
    		if(isok(dis,d,K))
    		{
    			r = d;
    			ans = d;
    		}
    		else
    			l = d;
    	}
    	return ans;
    }

    bool isok(vector<int>& dis, double d, int K)
    {	//每个站之间的相邻距离为 d, 增加 K 个站够吗？
    	int need = 0;
    	for(int i = 0; i < dis.size(); ++i)
    	{
    		need += ceil(dis[i]/d)-1;
    	}
    	return need <= K;
    }
};