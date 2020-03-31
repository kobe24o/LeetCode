class Solution {
public:
    int multiply(int A, int B) {
    	if(B==1)
    		return A;
    	if(A < B)
    		A^=B^=A^=B;//大的在前，少递归几次
    	if((B&1)==0)
    		return multiply(A,B>>1)<<1;
    	else
    		return A + (multiply(A,B>>1)<<1);
    }
};

class Solution {
public:
    int multiply(int A, int B) {
    	int i = 0, ans = 0;
    	if(A < B)
    		A^=B^=A^=B;//swap大的在前，少递归几次
    	while(B)//把B分解成2进制数，对每一位乘以A
    	{
    		if((B&1)==1)//该位为1(1,2,4,8,16)
    			ans += A<<i;//移动0,1,2,3,4位
    		B >>= 1;//B的每位移到最右 & 1来判断
    		i++;
    	}
    	return ans;
    }
};