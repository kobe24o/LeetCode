class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    	int i = 0, j = 0;
    	while(i < pushed.size())
    	{
    		if(pushed[i] == popped[j])
    		{
    			j++;
    			pushed.erase(pushed.begin()+i);
    			if(i != 0)
    				i--;
    		}
    		else if(i != pushed.size()-1)
    		{
    			i++;
    		}
    		else
    			return false;
    	}
    	return true;
    }
};