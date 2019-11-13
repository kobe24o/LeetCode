class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = chars[0]; 
        string num = "";
        int i, j = 1, k, n = chars.size(), count = 1;
        for(i = 1; i < n; i++) 
        {
        	if(chars[i] == prev)//跟前面相等
        	{
        		count++;//计数+1
        		if(i == n-1)
        		{
        			if(count != 1)
	        		{
	        			while(count)
	        			{
	        				num.push_back(count%10);
	        				count /= 10;
	        			}
	        			for(k = num.size()-1; k >= 0; --k)
	        				chars[j++] = num[k]+'0';
	        			// num = "";
	        		}
        		}
        	}
        	else
        	{
        		if(count != 1)
        		{
        			while(count)
        			{
        				num.push_back(count%10);
        				count /= 10;
        			}
        			for(k = num.size()-1; k >= 0; --k)
        				chars[j++] = num[k]+'0';
        			num = "";
        		}
        		prev = chars[i];
        		j++;//跳过第一个字符，不能覆盖
        		chars[j++] = chars[i];
        		count = 1;
        	}
        }
        return j;
    }
};