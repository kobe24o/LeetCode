/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
    	stack<int> stk;
    	int num = 0;
    	for(int i = 0; i < s.size(); ++i)
    	{
    		if(s[i] == '[')
    			num = 0;
    		else if(isdigit(s[i]))
    			num = num * 10 + s[i]-'0';
    		else if(s[i] == ',' || (isdigit(s[i-1]) && s[i] == ']'))
    		{
    			stk.push(num);
    		}
    	}
    	bool flag = false;
    	NestedInteger inner;
    	while(!stk.empty())
    	{
    		NestedInteger ni;
    		ni.setInteger(stk.top());
    		stk.pop();
    		if(flag == true)
    			ni.add(inner);
    		if(flag == false)
    			flag = true;
    		inner = ni;
    	}
    	return inner;
    }
};