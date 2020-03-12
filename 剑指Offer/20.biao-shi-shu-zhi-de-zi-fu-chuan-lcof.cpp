class Solution {
public:
    bool isNumber(string s) {
    	//去除尾部空格
		while(!s.empty() && s.back() == ' ')
			s.pop_back();
		while(!s.empty() && s.front() == ' ')
			s.erase(s.begin());//忽略头部空格
		if(s.empty())
			return false;
		int idx1 = s.find('E');
		int idx2 = s.find('e');
		if(idx1 == -1 && idx2 == -1)
			return check1(s);//没有指数，直接判断数字
		if(idx1 != -1)//找到指数，分成两半检查（s1）E（s2）
			return (check1(s.substr(0,idx1)) && check2(s.substr(idx1+1)));
		else	//找到指数，分成两半检查（s1）e（s2）
			return (check1(s.substr(0,idx2)) && check2(s.substr(idx2+1)));
    }

    bool check1(string s) 
    {	//前半部分
    	if(s.empty())
    		return false;
    	int dot = 0;
    	bool number = false;
    	for(int i = 0; i < s.size(); i++)
    	{
    		if((s[i]=='+' || s[i] == '-'))
    		{	//符号不在第一位
    			if(i != 0)
    				return false;
    		}
    		else if(s[i] == '.')
    			dot++;
    		else if(isdigit(s[i]))
    			number = true;
    		else//其他字符
				return false;
    	}
    	if(dot > 1 || !number)
    		return false;
    	return true;
    }

    bool check2(string s)
    {	//检查后半部分，不能有 . 点
    	if(s.empty())
    		return false;
    	bool number = false;
    	for(int i = 0; i < s.size(); i++)
    	{
    		if((s[i]=='+' || s[i] == '-'))
    		{	//符号不在首
    			if(i != 0)
    				return false;
    		}
    		else if(s[i] == '.')//指数不能有点
    			return false;
    		else if(isdigit(s[i]))
    			number = true;
    		else//其他字符
				return false;
    	}
    	if(!number)
    		return false;
    	return true;
    }
};