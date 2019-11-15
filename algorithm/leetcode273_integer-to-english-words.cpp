class Solution {
	unordered_map<int,string> bits = {{1,"One"},{2,"Two"},{3,"Three"},
									{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},
									{8,"Eight"},{9,"Nine"},{10,"Ten"},{11,"Eleven"},
									{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},
									{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},
									{18,"Eighteen"},{19,"Nineteen"},{20,"Twenty"},
									{30,"Thirty"},{40,"Forty"},{50,"Fifty"},
									{60,"Sixty"},{70,"Seventy"},{80,"Eighty"},{90,"Ninety"}};
public:
    string numberToWords(int num) {
    	if(num == 0)
    		return "Zero";
    	string ans, temp;
    	int i = 0;
    	vector<string> units = {"","Thousand","Million","Billion"};
    	while(num)
    	{
    		temp = tran(num%1000);
    		if(temp != "")//三位数都是0，跳过
    		{
    			temp = temp + (i>0 ? (" " + units[i]) : "");
    			ans = " " + temp + ans;
    		}
    		i++;
    		num /= 1000;//每3位一处理
    	}
    	if(ans.front() == ' ')    
    		ans = ans.substr(1);//最前面可能有空格，删除
    	return ans;
    }
    string tran(int num)//处理3位数
    {
    	if(num == 0)
    		return "";
    	string str;
    	int k = num/100;//百位数
    	if(k>0)
    		str = bits[k] + " " + "Hundred";
    	num %= 100;//后两位
    	if(num>0 && num <20)
    		if(str != "")//百位不为空
    			str += " " + bits[num];
    		else
    			str = bits[num];
    	else if(num >= 20)
    	{
    		k = num/10*10;// k = ？0
    		if(k != 0)
    		{
	    		if(str != "")//前面不为0
	    			str += " " + bits[k];
	    		else
	    			str += bits[k];
	    	}
    		num %= 10;//个位
    		if(num > 0)
    			if(str != "")//前面不为0
    				str += " " + bits[num];
    			else
    				str += bits[num];
    	}
    	return str;
    }
};