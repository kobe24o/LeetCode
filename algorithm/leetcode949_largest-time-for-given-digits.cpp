class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int m=0, i, j, i0, j0, minRec = INT_MAX;
        for(i = 0; i < 4; i++)
        {
        	for(j=i+1; j < 4; j++)
        	{
        		if(minRec > A[i]*10+A[j])
        			minRec = A[i]*10+A[j];
        		if(A[i]*10+A[j] <= 23 && A[i]*10+A[j] > m)
        		{
        			m = A[i]*10+A[j];
        			i0 = i, j0 = j;
        		}
        		if(minRec > A[j]*10+A[i])
        			minRec = A[j]*10+A[i];
        		if(A[j]*10+A[i] <= 23 && A[j]*10+A[i] > m)
        		{
        			m = A[j]*10+A[i];
        			i0 = i, j0 = j;
        		}
        	}
        }
        if(minRec > m)
        	return "";
        string time;
        time = m>=10 ? to_string(m) : ("0"+to_string(m));
        m = 0;
        minRec = INT_MAX;
        for(i = 0; i < 4; i++)
        {
        	for(j=i+1; j < 4; j++)
        	{
        		if(i==i0 || j==j0 || j==i0 || i==j0)
        			continue;
        		if(minRec > A[i]*10+A[j])
        			minRec = A[i]*10+A[j];
        		if(A[i]*10+A[j] <= 59 && A[i]*10+A[j] > m)
        			m = A[i]*10+A[j];
        		if(minRec > A[j]*10+A[i])
        			minRec = A[j]*10+A[i];
        		if(A[j]*10+A[i] <= 59 && A[j]*10+A[i] > m)
        			m = A[j]*10+A[i];
        	}
        }
        if(minRec > m)
        	return "";
        time += ":" + ((m>=10) ? to_string(m) : ("0"+to_string(m)));
        return time;
    }
};