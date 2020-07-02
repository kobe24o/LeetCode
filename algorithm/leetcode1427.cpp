class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
    	int l = 0, r = 0;
    	for(auto& move : shift)
    	{
    		if(move[0] == 0)
    			l += move[1];
    		else
    			r += move[1];
    	}
    	int n = abs(l-r)%s.size();
    	if(l-r > 0)
    		return s.substr(n)+s.substr(0,n);
    	return s.substr(s.size()-n)+s.substr(0,s.size()-n);
    }
};