class Solution {
public:
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
        	ans.insert(ans.begin(),curBit+'0');
        }
        if(one)
        	ans.insert(ans.begin(),'1');
        return ans;
    }
};