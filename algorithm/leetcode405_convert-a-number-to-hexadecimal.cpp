class Solution {
public:
    string toHex(int num) {
    	if(num == 0)
    		return "0";
        unsigned int k = num;
        string ans = "";
        char m[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while(k)
        {
        	ans.push_back(m[k%16]);
        	k /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};