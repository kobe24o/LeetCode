class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X >= Y)
            return X-Y;
        int n = 0;
		while((X<<1) < Y)
		{
			X <<= 1;   
			++n;
		}
		return n+1+Y-(X<<1);
    }
};