class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X >= Y)
            return X-Y;
        int n = 0;
		while(X != Y)
		{
			if((X <<= 1)>Y)
			{
				X--;
				++n;
			}
			++n;
		}
		return n;
    }
};