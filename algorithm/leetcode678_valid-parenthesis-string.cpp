#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int i, star = 0, left = 0, right = 0;
        for(i = 0; i < s.size(); ++i)
        {
        	if(s[i] == '(')
        		left++;
        	else if(s[i] == '*')
                star++;
        	else if(s[i] == ')')
        	{
        		if(left)
        			left--;
        		else if(star)
        			star--;
        		else
                    return false;
        	}
        }
        left = right = star = 0;
        for(i = s.size()-1; i >= 0; --i)
        {
        	if(s[i] == ')')
        		right++;
        	else if(s[i] == '*')
                star++;
        	else if(s[i] == '(')
        	{
        		if(right)
        			right--;
        		else if(star)
        			star--;
        		else
                    return false;
        	}
        }
        return true;
    }
};
int main()
{
	Solution s;
	cout << s.checkValidString("(())((())()()(*)(*()(())())())()()((()())((()))(*");
}

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> l;
        stack<int> star;
        for(int i = 0; i < s.size(); ++i)
        {
        	if(s[i] == '(')
        		l.push(i);
        	else if(s[i] == '*')
        		star.push(i);
        	else
        	{
        		if(l.empty() && star.empty())
        			return false;
        		if(!l.empty())
        			l.pop();
        		else
        			star.pop();
        	}
        }

        while(!l.empty() && !star.empty())
        {
        	if(l.top() > star.top())
        		return false;
        	l.pop();
        	star.pop();
        }
        return l.empty();
    }
};