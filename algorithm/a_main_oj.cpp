#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
#include <string>     // std::string, std::stoi
#include <map>
#include<stack>
# include<queue>
#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

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
                if(a != 0)
                    c = min(m[2*a], num);
                else
                    c = num/2;
                count += 2*c;
                m[a] -= c;
                m[2*a] -= c;
    		}
    	}
    	return count == A.size();
    }
};
//"0010 0110 0100 111"
//001001100100111
//001001100100111
int main()
{
    vector<int> l = {-8,-4,-2,-1,0,0,1,2,4,8};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{15,96},{36,2}};
     Solution s;
    string str = "abb";

    cout << s.canReorderDoubled(l) <<endl;



    cout << "hello" << endl;
    system("pause");
    return 0;
}


