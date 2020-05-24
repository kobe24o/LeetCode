class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
    	int l = 1, r = 1e9, mid;
    	while(l <= r)
    	{
    		mid = l+((r-l)>>1);
    		if(canFinish(piles,mid,H))
    			r = mid-1;
    		else
    			l = mid+1;
    	}
    	return l;
    }
    bool canFinish(vector<int> piles, int K, int H)
    {
    	int h = 0;
    	for(int i = 0; i < piles.size(); ++i)
    	{
    		// if(piles[i] > K)
    		// {
                // piles[i] -= K;//别模拟，数很大的时候，哭了

            //     i--;
            // }
    		// h++;
            h += ceil(piles[i]/double(K));
    		if(h > H)
    			return false;
    	}
    	return true;
    }
};