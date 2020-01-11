class Solution {
public:
    int nextGreaterElement(int number) {
        string str = to_string(number);
        if(str.size() <= 1)
        	return -1;
        int n = str.size(), i, j;
        bool found = false;
        for(i = n-2; i >= 0; --i)
        {
        	for(j = n-1; j > i; --j)
    		{
    			if(str[j] > str[i])
    			{
	    			swap(str[i],str[j]);
	    			found = true;
	    			break;
	    		}
    		}
        	if(found)
        		break;
        }
        if(!found)
        	return -1;
        sort(str.begin()+i+1,str.end());
        long num = 0;
        for(i = 0; i < n; ++i)
            num = num*10+str[i]-'0';
        if(num > INT_MAX)
            return -1;
        return num;
    }
};

class Solution {
public:
    int nextGreaterElement(int number) {
        string str = to_string(number);
        if(str.size() <= 1)
        	return -1;
        int n = str.size(), i=n-2, j=n-1;
        while(i >= 0 && str[i] >= str[i+1])
        	i--;
        if(i == -1)
        	return -1;
        while(j > i && str[j] <= str[i])
        	j--;
        swap(str[i],str[j]);

        i++; j=n-1;
        while(i < j)
        	swap(str[i++],str[j--]);
        long num = 0;
        for(i = 0; i < n; ++i)
            num = num*10+str[i]-'0';
        if(num > INT_MAX)
            return -1;
        return num;
    }
};