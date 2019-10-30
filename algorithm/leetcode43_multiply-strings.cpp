class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
        	return "0";
        int n1 = num1.size(), n2 = num2.size(), i, j;
        int bit1, bit2, carry, zero, curBit;
        string ans, temp;
        for(i = n2-1; i >= 0; i--)
        {
        	carry = 0;//进位清零
        	temp = "";//临时乘积
        	zero = n2-1-i;//后置添0个数
        	while(zero--)
        		temp.push_back('0');
        	bit2 = num2[i]-'0';
        	for(j = n1-1; j >= 0 || carry != 0; --j)
        	{
        		bit1 = j < 0 ? 0 : (num1[j]-'0');
        		curBit = (bit1*bit2+carry)%10;
        		temp.push_back(curBit+'0');
        		carry = (bit1*bit2+carry)/10;
        	}
        	reverse(temp.begin(),temp.end());//上面临时乘积是逆序的
        	ans = addStrings(ans,temp);//调用大数加法
        }
        return ans;
    }

    //LeetCode 415. 字符串相加（大数加法）
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        int i = n1-1, j = n2-1, one = 0, bit1, bit2, curBit;
        string ans;
        for( ; i >= 0 || j >= 0; --i,--j)
        {
        	bit1 =  i<0 ? 0 : (num1[i]-'0');
        	bit2 =  j<0 ? 0 : (num2[j]-'0');
        	curBit = (bit1+bit2+one)%10;
        	one = (bit1+bit2+one)/10;
        	ans.push_back(curBit+'0');
        }
        if(one)
        	ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
        	return "0";
        int n1 = num1.size(), n2 = num2.size(), i, j, curSum;
        int bit1, bit2, len = n1+n2;
        int res[len] = {0};//两数的乘积最多是n1+n2位
        string ans, temp;
        for(i = n2-1; i >= 0; i--)
        {
        	bit2 = num2[i]-'0';
        	for(j = n1-1; j >= 0; --j)
        	{
        		bit1 = num1[j]-'0';
        		curSum = res[i+j+1] + bit1*bit2;
        		res[i+j+1] = curSum % 10;
        		res[i+j] += curSum / 10;
        	}
        }

        for(i = 0; i < len; ++i)
        {
        	if(i == 0 && res[i] == 0)
        		continue;//前面可能有一个0，跳过
        	ans.append(to_string(res[i]));
        }
        return ans;
    }
};