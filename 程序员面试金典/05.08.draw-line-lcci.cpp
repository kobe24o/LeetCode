class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        int n = w>>5, idx = y*n;
        vector<int> ans(length,0);
        while(x1 > 31)
        {
        	idx++;
        	x1 -= 32;
        	x2 -= 32;
        }
        int l = x1, r;
        for( ; x2>=0; l=0,x2-=32)
        {
        	r = min(x2,31);
        	for(int i = l; i <= r; i++)
        	{
        		ans[idx] |= 1<<(31-i);
        	}
        	idx++;
        }
        return ans;
    }
};