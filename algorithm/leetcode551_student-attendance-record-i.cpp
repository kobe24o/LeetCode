class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        char prev = 'x';
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i] == 'A')
        	{
        		A++;
        		if(A > 1)
        			return false;
        		prev = 'A';
        		L = 0;
        	}
        	else if(s[i] == 'L')
        	{
        		if(prev == 'L')
        			L++;
        		else
        			L=1;
        		prev = 'L';
        		if(L > 2)
        			return false;
        	}
        	else
        	{
        		prev = 'P';
        		L = 0;
        	}
        }
        return true;
    }
};