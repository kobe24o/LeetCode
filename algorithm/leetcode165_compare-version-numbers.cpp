#include<string>
using namespace std;
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1, n2, i, j;
        for(i=0,j=0; i < v1.size() || j < v2.size(); ++i,++j)
        {
        	n1=n2=0;
        	while(i < v1.size() && v1[i] != '.')
        		n1 = n1*10 + v1[i++]-'0';
        	while(j < v2.size() && v2[j] != '.')
        		n2 = n2*10 + v2[j++]-'0';
        	if(n1 > n2)
        		return 1;
        	else if(n1 < n2)
        		return -1;
        }
        return 0;
    }
};
int main()
{
	Solution s;
	s.compareVersion("001.1.0","1.1");
}