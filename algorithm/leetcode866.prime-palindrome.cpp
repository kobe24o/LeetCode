class Solution {
public:
    int primePalindrome(int N) {
        if(N==1)
            return 2;
        if(8<=N && N<=11)
            return 11;
        int bit;
        for(;N;++N)
        {
            if(10000000 < N && N < 100000000)
                N = 100000000;//没有8位数的回文素数
            if(isPalindrome(N,bit) && (bit%2) && isPrime(N))//奇数位的回文数才可能是质数，除11
                return N;
        }
        return -1;
    }

    bool isPalindrome(int n, int &bit)
    {
        int t = 0, N = n;
        bit = 0;
        while(n)
        {
            t = t*10+n%10;
            n /= 10;
            bit++;
        }
        return (t==N);
    }
    bool isPrime(int n)
    {
        for(int i = 2; i <= sqrt(n); i++)
            if(n%i==0)
                return false;
        return true;
    }
};