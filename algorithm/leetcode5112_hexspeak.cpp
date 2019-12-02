class Solution {
public:
    string toHexspeak(string num) {
        long n = 0;
        int i, mod;
        char ch[16] = {'O','I','-','-','-','-','-','-','-','-',
        					'A','B','C','D','E','F'};
        for(i = 0; i < num.size(); ++i)
        	n = n*10 + num[i]-'0';
        string ans;
        while(n)
        {
        	mod = n%16;
        	if(!(mod >= 10 || mod == 0 || mod ==1))
        		return "ERROR";
        	ans += ch[mod];
        	n /= 16;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};