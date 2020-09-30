class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
    	unordered_map<int,int> m;
    	for(int a : A)
    		m[a]++;
    	int count = 0, a, a2, num, num2, c;
    	for(auto it = m.begin(); it != m.end(); ++it)
    	{
    		a = it->first;
    		num = it->second;
    		if(m.count(2*a) && m[2*a] > 0)
    		{
    			c = min(m[2*a], num);
    			count += c;
    			m[a] -= c;
    			m[2*a] -= c;
    		}
    	}
    	return count >= A.size()/2;
    }
};