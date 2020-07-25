class Solution {
public:
    int minNumberOperations(vector<int>& target) {
    	int s = 0;
        target.push_back(0);
    	for(int i = 1; i < target.size(); ++i)
    	{
			if(target[i-1] > target[i])
    			s += target[i-1]-target[i];
    	}
    	return s;
    }
};