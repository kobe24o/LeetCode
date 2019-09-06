class Solution {
public:
    int myAtoi(string str) {
    	int d=0;
        istringstream is(str);
        is >> d;
        return d;
    }
};