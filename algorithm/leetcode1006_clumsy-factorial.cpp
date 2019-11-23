class Solution {
public:
    int clumsy(int N) {
        int i, ans = 0;
        int left = N, right;
        N--;
        for(i = 0 ; N; N--,i++)
        {
        	right = N;
        	i = i%4;
        	if(i==0)
        		left *= right;
        	else if(i==1)
        		left /= right;
        	else if(i==2)
        		ans += left+right;
        	else
        		left = -right;
        }
        if(i != 3)
        	ans += left;
        return ans;
    }
};