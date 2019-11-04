class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int N = seats.size(), i, prev = 0, maxDis = -1, mid;
        for(i = 0; i < N; i++) 
        {
        	if(seats[i])//有人
        	{
        		mid = (prev+i)/2;
        		if(seats[prev])
        			maxDis = max(maxDis,min(mid-prev,i-mid));
        		else//i是第一个人
        			maxDis = i;
        		prev = i;
        	}
        	else if(i == N-1 && !seats[i])
        		maxDis = max(maxDis,i-prev);
        }
        return maxDis;
    }
};