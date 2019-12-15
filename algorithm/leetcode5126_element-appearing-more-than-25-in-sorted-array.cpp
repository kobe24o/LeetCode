class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int i, n, prev = arr[0], count = 1;
        n = arr.size()/4+1;
        for(i = 1; i < arr.size(); ++i)
        {
        	if(arr[i] == prev)
            {
                count++;
                if(count >= n)
        		    return prev;
            }
        	else
        	{
        		count = 1;
        		prev = arr[i];
        	}
        }
        return prev;
    }
};

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int i, n = arr.size()/4;
        for(i = n; i < arr.size(); ++i)
        {
        	if(arr[i-n] == arr[i] || arr[i] == arr[i+n])
            {
        		return arr[i];
            }
        }
        return -1;
    }
};