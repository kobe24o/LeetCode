class Solution {
public:
    int monotoneIncreasingDigits(int N) {
    	if(N < 10)
    		return N;
        string num;
        while(N)//数字转字符串
        {
        	num = to_string(N%10) + num;
        	N /= 10;
        }
        int i, k, ans = 0;
        for(i= 0; i < num.size()-1; ++i)
        {
        	if(num[i] > num[i+1])//第一个下降的地方
        	{
        		k = i-1;
        		while(k >= 0 && num[k] == num[i])//前面有跟它一样的 332
        			k--;
        		num[++k]--;//最前面的一位 -1
                for(++k; k < num.size(); ++k)//后面所有的位变成 9
        	        num[k] = '9';
        		break;
        	}
        }       
    	for(i=0; i < num.size(); ++i)//字符串转数字
    		ans = ans*10+ num[i]-'0';
    	return ans;
    }
};