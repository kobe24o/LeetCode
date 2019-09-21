#include <iostream>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        n = n^(n>>1);
        return (((long)n+1)&n) == 0;
    }
};
int main()
{
	// Solution s;
	// cout << s.hasAlternatingBits(5);
	int n = 4;
	int k = n&(n>>1);
	cout << (n>>1) << n << k << bool((n&(n>>1)) == 0) << endl;
}