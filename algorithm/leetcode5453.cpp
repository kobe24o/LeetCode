class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    	int t = 0;
    	for(int pos : left)
    		t = max(t, pos);
    	for(int pos : right)
    		t = max(t, n-pos);
    	return t;
    }
};