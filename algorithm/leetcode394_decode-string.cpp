#include <string>
#include<iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        int i, j, n = 0, num;
        string str, temp, ans;
        stack<int> intStk;
        stack<char> charStk;
        for(i = 0; i < s.size(); ++i)
        {
        	if(s[i] >= '0' && s[i] <= '9')
        		n = n*10 + s[i] - '0';//记录整数是啥
        	else if(!(s[i] >= '0' && s[i] <= '9') && s[i] != ']')
        	{
        		if(s[i] == '[')//整数存好了
        		{
        			intStk.push(n);
        			n = 0;//为下次准备好自己
        		}
        		charStk.push(s[i]);
        	}
        	else//s[i] == ']'
        	{
        		num = intStk.top();//取出数字
        		intStk.pop();
        		while(charStk.top() != '[')
        		{
        			temp = charStk.top()+temp;//[]里面是啥呢？temp
        			charStk.pop();
        		}
        		charStk.pop();//'['
        		while(num--)//字符temp*num次
        		{
        			str += temp;
        		}
                for(j = 0; j < str.size(); ++j)//把得到的str入栈
                    charStk.push(str[j]);
        		str = temp = "";//为下次做准备
        	}
        }
        while(!charStk.empty())//取出所有结果
        {
        	ans = charStk.top()+ans;
        	charStk.pop();
        }
        return ans;
    }
};
int main()
{
	Solution s;
	cout << s.decodeString("3[a]2[bc]");
	return 0;
}