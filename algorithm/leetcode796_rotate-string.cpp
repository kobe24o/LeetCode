class Solution {
	int i, n;
	char ch;
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size())
        	return false;
        n = A.size();
        if(n<=1)
        	return A==B;
        int t = n;
        while(t--)
        {
        	movestr(A);
        	if(A==B)
        		return true;
        }
        return false;
    }

    void movestr(string &s)
    {
    	ch = s[n-1];
    	i = n-1;
    	while(i-1>=0)
    	{
    		s[i] = s[i-1];
    		i--;
    	}
    	s[0] = ch;
    }
};