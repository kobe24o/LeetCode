class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0, i;
        for(i = 0; i < 32; ++i)
        {
            if((c>>i)&1)//c该位为1
            {
                if((((a>>i)&1)==0) && (((b>>i)&1)==0))
                    flip++;//当a,b,该位都为0时，翻一位就可以了
            }
            else//c该位为0
            {
                if((((a>>i)&1)==1) && (((b>>i)&1)==0))
                    flip++;
                else if((((a>>i)&1)==0) && (((b>>i)&1)==1))
                    flip++;
                else if((((a>>i)&1)==1) && (((b>>i)&1)==1))
                    flip += 2;
            }
        }
        return flip;
    }
};