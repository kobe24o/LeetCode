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
    int bagOfTokensScore(vector<int>& tokens, int P) {
    	int points = 0, maxPoints = 0, n = tokens.size();
    	sort(tokens.begin(), tokens.end());
    	if(n==0 || P < tokens[0])
    		return 0;
    	int l = 0, r = n-1;
    	while(l <= r)
    	{
    		if(P > tokens[l])//能量够，去拿分
    		{
    			points++;
    			P -= tokens[l];
    			l++;
    		}
    		else
    		{
                points--;
                P += tokens[r];
                r--;
            }
    		maxPoints = max(points, maxPoints);
    	}
    	return maxPoints;
    }
};
//"0010 0110 0100 111"
//001001100100111
//001001100100111
int main()
{
    vector<int> l = {100,200,300,400};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{15,96},{36,2}};
     Solution s;
    string str = "abb";

    cout << s.bagOfTokensScore(l,200) <<endl;



    cout << "hello" << endl;
    system("pause");
    return 0;
}


