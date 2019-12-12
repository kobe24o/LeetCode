class Solution {
public:
    string originalDigits(string s) {
        int count[26] = {0};
        for(auto& ch : s)
        	count[ch-'a']++;
        int num[10] = {0};
        num[0] = count['z'-'a'];
        count['z'-'a'] -= num[0];
        count['e'-'a'] -= num[0];
        count['r'-'a'] -= num[0];
        count['o'-'a'] -= num[0];
        num[2] = count['w'-'a'];
        count['t'-'a'] -= num[2];
        count['w'-'a'] -= num[2];
        count['o'-'a'] -= num[2];
        num[4] = count['u'-'a'];
        count['f'-'a'] -= num[4];
        count['o'-'a'] -= num[4];
        count['u'-'a'] -= num[4];
        count['r'-'a'] -= num[4];
        num[6] = count['x'-'a'];
        count['s'-'a'] -= num[6];
        count['i'-'a'] -= num[6];
        count['x'-'a'] -= num[6];
        num[8] = count['g'-'a'];
        count['e'-'a'] -= num[8];
        count['i'-'a'] -= num[8];
        count['g'-'a'] -= num[8];
        count['h'-'a'] -= num[8];
        count['t'-'a'] -= num[8];
        num[1] = count['o'-'a'];
        count['o'-'a'] -= num[1];
        count['n'-'a'] -= num[1];
        count['e'-'a'] -= num[1];
        num[3] = count['t'-'a'];
        count['t'-'a'] -= num[3];
        count['h'-'a'] -= num[3];
        count['r'-'a'] -= num[3];
        count['e'-'a'] -= 2*num[3];
        num[5] = count['f'-'a'];
        count['f'-'a'] -= num[5];
        count['i'-'a'] -= num[5];
        count['v'-'a'] -= num[5];
        count['e'-'a'] -= num[5];
        num[7] = count['s'-'a'];
        count['s'-'a'] -= num[7];
        count['e'-'a'] -= 2*num[7];
        count['v'-'a'] -= num[7];
        count['n'-'a'] -= num[7];
        num[9] = count['i'-'a'];
        string ans;
        for(int i = 0; i < 10; ++i)
        {
        	while(num[i]--)
        		ans += to_string(i);
        }
        return ans;
    }
};