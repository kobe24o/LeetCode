class Solution {
public:
    string strWithout3a3b(int A, int B) {
        int n = min(A,B), i = 0;
        string ans;
        while(n--)
        	if(A>=B)
        		ans += "ab";
        	else
        		ans += "ba";
        A -= n;
        B -= n;
        if(A)
        {
        	while(A--)
        	{
        		ans.insert(i,1,'a');
        		i += 3;
        	}
        }
        if(B)
        {
        	while(B--)
        	{
        		ans.insert(i,1,'b');
        		i += 3;
        	}
        }
        return ans;
    }
};