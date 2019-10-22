class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
        	return 0;
        int count = 1;//质数2
        bool isTrue;
        for(int k = 3; k < n; k++)
        {
        	isTrue = 1;
        	for(int i = 2; i <= sqrt(k)+1; ++i)
        		if(k%i == 0)
        		{
        			isTrue = 0;
        			break;
        		}
    		if(isTrue)
    			count++;
    	}
    	return count;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
        	return 0;
        bool isTrue[n];
        memset(isTrue,true,n*sizeof(bool));
        int count = 0;
        for(int i = 2; i < n; ++i)
        {
        	if(isTrue[i])
        		for(int j = 2*i; j < n; j = j+i)
        			isTrue[j] = false;
        }

        for(int i = 2; i < n; ++i)
        	if(isTrue[i])
        		count++;
    	return count;
    }
};