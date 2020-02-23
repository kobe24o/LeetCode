class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    	int indegree[n]  = {0};
    	int outdegree[n] = {0};
    	bool findroot = false;
    	int i, sum = 0;
    	for(i = 0; i < n; ++i)
    	{
    		if(leftChild[i] != -1)
    			indegree[leftChild[i]]++;
    		if(rightChild[i] != -1)
    			indegree[rightChild[i]]++;	
    	}
    	for(i = 0; i < n; ++i)
    	{
    		if(!findroot && indegree[i]==0)
    			findroot = true;
    		else if(findroot && indegree[i]==0)
    			return false;
    		else if(indegree[i] > 1)
    			return false;
    		sum += indegree[i];
    	}
    	if(sum != n-1)
    		return false;
    	return true;
    }
}; 