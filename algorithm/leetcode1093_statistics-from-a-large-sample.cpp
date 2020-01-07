class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int i, MIN = -1, MAX, avg, median = 0, mode;
        int n = 0, ni = 0, N;
        long sum = 0;
        for(i = 0; i < count.size(); ++i)
        {
        	if(count[i])
        	{
        		if(MIN == -1)
        			MIN = i;
        		MAX = i;
        		n += count[i];
        		sum += count[i]*i;
        		if(count[i] > ni)
        		{
        			ni = count[i];
        			mode = i;
        		}
        	}
        }
       	vector<double> ans({MIN,MAX,double(sum)/n,0,mode});
       	ni = 0;
       	bool flag = false;
       	for(i = 0; i < count.size(); ++i)
       	{
       		if(n%2)
       		{
       			if(ni+count[i] < n/2+1)
       				ni += count[i];
       			else
       			{
       				ans[3] = i;
       				break;
       			}
       		}
       		else
       		{
       			N = ni + count[i];
       			if(N < n/2)
       				ni += count[i];
       			else if(N >= n/2 && N < n/2+1)
       			{
       				ans[3] = i;
       				flag = true;
       			}
       			else
       			{
       				if(!flag)
       				{
       					ans[3] = i;
       					break;
       				}
       				else
       				{
       					ans[3] = double(ans[3]+i)/2;
       					break;
       				}
       			}
       		}
       	}
       	return ans;
    }
};