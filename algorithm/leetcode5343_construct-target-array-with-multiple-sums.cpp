class Solution {
public:
    bool isPossible(vector<int>& target) {
        sort(target.rbegin(), target.rend());//降序
        int i, sum = 0, ones = 0;
        for(i = 0; i < target.size(); ++i)
        	sum += target[i];
        for(i = 0; i < target.size(); ++i)
        {
        	ones++;
        	sum -= target[i];
        	if(sum+ones != target[i])
        		return false;
        }
        return true;
    }
};