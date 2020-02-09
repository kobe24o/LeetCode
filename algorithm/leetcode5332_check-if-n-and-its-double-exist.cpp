class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(int i = 0; i < arr.size(); ++i)
        {
        	if(s.count(arr[i]*2) || (arr[i]%2==0 && s.count(arr[i]/2)))
        		return true;
        	if(s.count(arr[i]) == 0)
        		s.insert(arr[i]);
        }
        return false;
    }
};