class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
    	int i, zeros = 0;
        for(i = 0; i < arr.size(); ++i)
        {
        	if(arr[i] == 0)
        		zeros++;
        }
        for(i = arr.size()-1; i >= 0; --i)
        {
        	if(arr[i] == 0)
        	{
        		--zeros;//除去本身，还有n-1个零
        		if(i+zeros < arr.size())
        			arr[i+zeros] = 0;//本身的0
        		if(i+zeros+1 < arr.size())
        			arr[i+zeros+1] = 0;//新增的0	
        	}
        	else
        	{
        		if(i+zeros < arr.size())
        			arr[i+zeros] = arr[i];
        	}
        }
    }
};