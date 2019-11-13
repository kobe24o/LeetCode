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
        		if(i == n-1 && count != 1)//是最后一个字符吗？
        		{	//只有一个字符的话，不需要写数字1
        			while(count)//将计数的每位拆开
        			{
        				num.push_back(count%10);
        				count /= 10;
        			}
        			//将每位，赋值到原数组
        			for(k = num.size()-1; k >= 0; --k)
        				chars[j++] = num[k]+'0';
        		}
        	}
        	else//跟前面不相等
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
        			num = "";//处理好了，为下次做准备，清空
        		}
        		prev = chars[i];
        		chars[j++] = chars[i];//上面数字填好了，该字母了
        		count = 1;//计数重置为1个
        	}
        }
        return j;//j的位置就是新数组的长度
    }
};