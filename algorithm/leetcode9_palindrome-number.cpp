class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x%10 == 0 && x != 0)
        	return false;
        int reverse = 0, pos, copy = x;
        while(copy)
        {
        	pos = copy%10;
        	copy /= 10;
        	reverse = reverse*10 + pos;
        }
        return reverse == x;
    }
};