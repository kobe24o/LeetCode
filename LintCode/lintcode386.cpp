class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int i = 0, j = 0, MAX = 0, n = s.size(), count = 0;
        unordered_map<char,int> m;
        char ch;
        for( ; j < n; j++) 
        {
            ch = s[j];
            if (m[ch] == 0) //右端点有新的字符
                count++;
            m[ch]++;
            if(count > k) //字符种类超了
            {
                ch = s[i++];
                m[ch]--;
                if(m[ch] == 0) 
                    count--;//如果为0，种类减少
            }
            MAX = j-i+1;//MAX只增不减，是最后的答案
        }
        return MAX;
    }
};