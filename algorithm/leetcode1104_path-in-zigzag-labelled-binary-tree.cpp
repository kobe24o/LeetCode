#include <vector>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int n = 1;
        while(pow(2,n-1) < label)
        	n++;
        while(n--)
        {
        	ans.push_back(label);
        	label = 3*pow(2,n-1)-1 - (label>>1);
        }
        return ans;
    }
};
int main()
{
	Solution s;
	s.pathInZigZagTree(14);
}