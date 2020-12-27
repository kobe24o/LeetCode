class Solution {
public:
    string maximumBinaryString(string binary) {
        int one1 = 0, oneall = 0, n = binary.length();
        bool meetzero = false;//遇到第一次0
        for(int i = 0; i < n; i++)
        {   
            if(binary[i] == '1')
            {
                oneall++;
                if(!meetzero)
                    one1++;//左端连续的1
            }
            else
                meetzero = true;
        }
        return string(one1,'1') // 左端的1不动
            +(n-oneall > 0 ? (string(n-oneall-1,'1')+'0') : "") // 中间的0000变成1110，留一个0
            +string(oneall-one1,'1');//剩余的1全部移到右边
    }
};