class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0)
        	return "";
        if(numerator == 0)
        	return "0";
        string ans;

        long num = numerator, denom = denominator;
        if((num>0)^(denom>0))//一正一负
        	ans.push_back('-');
        num = abs(num);
        denom = abs(denom);//都转换为整数
        //处理整数部分
        ans.append(to_string(num/denom));

        //处理小数部分
        num %= denom;
        if(num == 0)
        	return ans;
        ans.push_back('.');
        int idx = ans.size()-1;//小数点的下标
        unordered_map<int,int> m;//记录循环出现的小数
        while(num && m.count(num)==0)//余数不为0，且没有出现过
        {
        	m[num] = ++idx;//记录数字的下标
        	num *= 10;//余数扩大10倍
        	ans.append(to_string(num/denom));
        	num %= denom;
        }
        if(m.count(num) == 1)
        {
        	ans.insert(m[num],"(");
        	ans.push_back(')');
        }
        return ans;
    }
};