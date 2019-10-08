class Solution {
public:
    string getHint(string secret, string guess) {
        int c1[10]={0}, c2[10]={0}, na = 0, nb = 0;
        for(int i = 0; i < secret.size(); ++i)
        {
        	if(secret[i] == guess[i])
        		na++;
        	else
        	{
        		c1[secret[i]-'0']++;
        		c2[guess[i]-'0']++;
        	}
        }
        for(int i = 0; i < 10; ++i)
        {
        	nb += min(c1[i], c2[i]);
        }
        return to_string(na)+"A"+to_string(nb)+"B";
    }
};