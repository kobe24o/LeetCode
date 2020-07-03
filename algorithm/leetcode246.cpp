class Solution {
public:
    bool isStrobogrammatic(string num) {
    	unordered_map<char,char> m = {{'6','9'},{'9','6'},{'8','8'},{'1','1'},{'0','0'}};
    	string rotate;
    	for(char ch : num)
    	{
    		if(!m.count(ch))
    			return false;
    		rotate = m[ch]+rotate;
    	}
    	return rotate==num;
    }	
};