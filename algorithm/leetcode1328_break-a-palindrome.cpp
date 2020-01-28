class Solution {
public:
    string breakPalindrome(string palindrome) {
        int i = 0, n = palindrome.size();
        if(n <= 1)
            return "";
        while(i < n && palindrome[i] <= 'a')
            i++;
        if(i == n)//全部为a
        {
            palindrome[n-1] = 'b';//最后一个改成b
            return palindrome;
        }
        if(n%2==1 && i ==((n-1)/2))//奇数个字符，且找到的是中间的字符可以修改
        {
            i++;//去下一位找，修改中间的，还是回文串
            while(i < n && palindrome[i] <= 'a')
                i++;
            if(i == n)
            {
                palindrome[n-1] = 'b';
                return palindrome;
            }   
        }
        palindrome[i] = 'a';
        return palindrome;
    }
};