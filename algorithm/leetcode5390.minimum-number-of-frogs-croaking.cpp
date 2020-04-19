class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
    	int i, frog=0, c, r, o, a, k;
    	c=r=o=a=k=i=0;
    	for(i = 0; i < croakOfFrogs.size(); ++i)
    	{
    		if(croakOfFrogs[i]=='c') c++;
    		else if(croakOfFrogs[i]=='r') r++;
    		else if(croakOfFrogs[i]=='o') o++;
    		else if(croakOfFrogs[i]=='a') a++;
    		else k++;
    		if(!(c>=r&&r>=o&&o>=a&&a>=k)) return -1;
    		if(i == croakOfFrogs.size()-1 && !(a==r&&r==o&&o==a&&a==k))
    			return -1;
    		frog = max(frog,max(c,max(r,max(o,max(a,k)))));
    		if(c&&r&&o&&a&&k)
    			c--,r--,o--,a--,k--;
    	}
    	return frog;
    }
};