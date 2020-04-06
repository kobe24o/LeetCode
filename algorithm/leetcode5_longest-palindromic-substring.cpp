class Solution {
public:
    string longestPalindrome(string s) {
        int i, j, len, n = s.size(), maxLen = 0;
        if(n <= 1)
            return s;
        string ans;
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<vector<bool>> same(n,vector<bool>(n,false));
        //表示区间[i,j]的最大回文长度
        for(i = 0; i < n; ++i)
        {
        	dp[i][i] = 1;//单个字符是回文
        	same[i][i] = true;//区间内字符都一样吗
        }
        for(len = 1; len < n; ++len)
        {
        	for(i = 0; i < n-len; ++i)
        	{
        		if(dp[i][i+len-1])//【i,i+len-1】是回文串
        		{
	        		if(same[i][i+len-1])//区间内都一样
	        		{	//奇数个字符的回文---> +1变偶数长度(必须区间内全相等)
	        			//偶数个字符的回文---> +1变奇数长度(必须区间内全相等)
	        			if(i-1 >= 0)
	        			{
	        				if(s[i-1]==s[i+len-1])//左边增加1个字符
		        			{
		        				dp[i-1][i+len-1] = 1 + dp[i][i+len-1];
		        				same[i-1][i+len-1] = true;
		        			}
		        			if(s[i-1]==s[i+len])//左右各增加1个
		        			{
		        				if(s[i-1]==s[i])
		        					same[i-1][i+len] = true;
		        				dp[i-1][i+len] = 2 + dp[i][i+len-1];
		        			}
	        			}
	        			if(s[i+len]==s[i])//右边增加1个
	        			{
	        				dp[i][i+len] = 1 + dp[i][i+len-1];
	        				same[i][i+len] = true;
	        			}
	        		}
	        		else//区间[i, i+len-1]内字符不一样,只能+2个字符上来
	        		{
	        			if(i-1>=0 && s[i-1]==s[i+len])
	        				dp[i-1][i+len] = 2 + dp[i][i+len-1];
	        		}
	        	}
                if(i-1>=0)
                {
                    if(dp[i-1][i+len-1] > maxLen)
                    {
                        maxLen = dp[i-1][i+len-1];
                        ans = s.substr(i-1,maxLen);
                    }
                    if(dp[i-1][i+len] > maxLen)
                    {
                        maxLen = dp[i-1][i+len];
                        ans = s.substr(i-1,maxLen);
                    }
                }
                if(dp[i][i+len-1] > maxLen)
                {
                    maxLen = dp[i][i+len-1];
                    ans = s.substr(i,maxLen);
                }
                if(dp[i][i+len] > maxLen)
                {
                    maxLen = dp[i][i+len];
                    ans = s.substr(i,maxLen);
                }
        	}
        }
        return ans;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        int i, j, len, n = s.size(), maxLen = 1;
        string ans = s.substr(0,1);
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(i = 0; i < n; ++i)
        {
            dp[i][i] = true;
            if(i < n-1 && s[i]==s[i+1])
            {
                dp[i][i+1] = true;
                if(maxLen < 2)
                {
                    maxLen = 2;
                    ans = s.substr(i,2);
                }
            }
        }
        for(len = 1; len < n; ++len)
        {
            for(i = 0; i < n-len; ++i)
            {
                if(dp[i][i+len-1] && i-1>=0 && s[i-1]==s[i+len])//是回文串
                {
                    dp[i-1][i+len] = true;
                    if(len+2 > maxLen)
                    {
                        maxLen = len+2;
                        ans = s.substr(i-1,maxLen);
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        int i, j, len, len1, len2, n = s.size(), maxLen = 0;
        string ans;
        for(i = 0; i < n; ++i)
        {
            len1 = centerspand(s,i,i);
            len2 = centerspand(s,i,i+1);
            len = max(len1,len2);
            if(len > maxLen)
            {
                maxLen = len;
                ans = s.substr(i-(len-1)/2, len);
            }
        }
        return ans;
    }
    int centerspand(string& s, int l, int r)
    {
        int len = 0;
        if(l==r)
            len++,l--,r++;
        while(l>=0 && r<s.size())
        {
            if(s[l]==s[r])
                len += 2;
            l--;r++;
        }
        return len;
    }
};