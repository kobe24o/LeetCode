#include<unordered_set>
#include<string>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.find("0000") != dead.end())
            return -1;
        unordered_set<string> visited;
        queue<string> q;
        string tp;
        int step = 0, n, i, j;
        vector<int> dir = {1,-1};
        q.push("0000");
        visited.insert("0000");
        while(!q.empty()) 
        {
        	n = q.size();
        	while(n--)
        	{
        		tp = q.front();
        		q.pop();
        		if(tp == target)
        			return step;
        		for(i = 0; i < 4; ++i)
        		{
        			for(j = 0; j < 2; ++j)
        			{
        				if(j == 0)
        					tp[i] = tp[i] == '9' ? '0' : tp[i]+1;
        				else
        					tp[i] = tp[i] == '0' ? '9' : tp[i]-1;
        				if(visited.find(tp) == visited.end() && dead.find(tp) == dead.end())
        				{
        					visited.insert(tp);
        					q.push(tp);
        				}
        			}
        		}
        	}
        	++step;
        }
        return -1;
    }
};

int main()
{
	Solution s;
	vector<string> d = {"8888"};
	s.openLock(d,"0009");
}