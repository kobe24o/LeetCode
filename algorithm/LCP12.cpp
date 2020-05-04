class Solution {
public:
    int minTime(vector<int>& time, int m) {
    	int Tl = 0, Tr = 0, Tmid, i, n = time.size();
    	for(i = 0; i < n; ++i)
    		Tr += time[i];
    	while(Tl <= Tr)
    	{
    		Tmid = Tl+((Tr-Tl)>>1);
    		if(check(time,Tmid,m))//可以完成
    			Tr = Tmid-1;
    		else
    			Tl = Tmid+1;
    	}
    	return Tl;
    }
    bool check(vector<int>& time, int t, int m)
    {	//每天最多花费t时间, 小于等于m天做完
    	int maxCost = 0, days = 1, totalcost = 0, i;
    	bool chancetohelp = true;
    	for(i = 0; i < time.size(); ++i)
    	{
    		maxCost = max(maxCost, time[i]);//最耗时的题
    		totalcost += time[i];
    		if(totalcost > t)//超过限制
    		{
    			if(chancetohelp)//可以求助
    			{
    				chancetohelp = false;
    				totalcost -= maxCost;//求助使用，耗时最多的    				
    			}
    			else//不能求助了
    			{
    				days++;
    				totalcost = 0;
                    maxCost = 0;
    				i--;
    				chancetohelp = true;
    			}
    		}	
    	}
    	return days <= m;
    }
};