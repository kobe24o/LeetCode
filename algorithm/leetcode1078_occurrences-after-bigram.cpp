#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        string cur;
        bool firstEq, secondEq;
        firstEq = secondEq = false;
        for(int i = 0; i < text.size(); ++i)
        {
        	if(text[i] == ' ' && i != text.size()-1)
        	{
        		if(firstEq == true && secondEq == false)
        		{
        			if(cur == second)
        				secondEq = true;
        			else
                    {
        			    if(cur != first)
        			        firstEq = false;
                    }
        		}
        		else if(firstEq == false)
        		{
        			if(cur == first)
        				firstEq = true;
        		}
        		else if(firstEq == true && secondEq == true)
        		{
        			ans.push_back(cur);
        			cur == first ? firstEq = true : firstEq = false;
        			secondEq = false;
        		}
        		cur = "";
        	}
        	else if(i == text.size()-1)
        	{
        		cur.push_back(text[i]);
        		if(firstEq == true && secondEq == true)
        			ans.push_back(cur);
        	}
        	else
        		cur.push_back(text[i]);
        }
        return ans;
    }
};
int main()
{
	Solution s;
	s.findOcurrences("ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv ypkk"
,"lnlqhmaohv"
,"ypkk");
}