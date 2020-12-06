#include <bits/stdc++.h>

using namespace std;


struct cmp{
    bool operator()(char a, char b) const
    {
        return a > b;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
    	unordered_map<int, int> m;
    	for(auto n : nums)
    		m[n]++;
    	int sum = 0, num, count, target, add;
    	for(auto& num_count : m)
    	{
    		num = num_count.first;
    		count = num_count.second;
    		if(count == 0)
    			continue;
    		target = k-num;
            if(target != num)
    	        add = min(count, m[target]);
            else
                add = count/2;
    		sum += add;
    		num_count.second -= add;
            if(num == 6)
                cout << num << " " << target <<  endl;
    		m[target] -= add;
    	}
    	return sum;
    }
};
int main()
{

    Solution s;
    vector<int> a = {29,26,81,70,75,4,48,38,22,10,51,62,17,50,7,7,24,61,54,44,30,29,66,83,6,45,24,49,42,31,10,6,88,48,34,10,54,56,80,41,19};
    string s1 = "D450";
    cout << s.maxOperations(a,12) << endl;
    return 0;
}