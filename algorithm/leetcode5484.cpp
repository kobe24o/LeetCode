class Solution {
public:
    char findKthBit(int n, int k) {
        if(k==1 || n==1)
            return '0';
        k--;
        int len = (1<<n)-1;//字符串长度为2^n-1
        if(k == len/2) return '1';
        bool reverse = false;
        while(n) 
        {
            len = (1<<n)-1;//字符串长度为2^n-1
            if(k == 0)//找到最前面了，状态不会再变
                break;
            else if(k > len/2) 
            {
                reverse = !reverse;//后半部分会反转状态
                k = len-1-k;//位置对应于前一个字符的位置
            }
            n--;
        }
        return reverse ? '1' : '0';
    }
};

class Solution {
public:
    char findKthBit(int n, int k) {
        if(k==1 || n==1)
            return '0';
        k--;
        int len = (1<<n)-1;//字符串长度为2^n-1
        if(k == len/2) return '1';
        return dfs(n, k);
    }

    char dfs(int n, int k)
    {
        if(n==1 || k == 0)
            return '0';
        int len = (1<<n)-1;
        if(k == len/2) 
            return '1';
        if(k > len/2)           
            return dfs(n-1, len-1-k)=='1' ? '0' : '1';
        return dfs(n-1, k);
    }
};