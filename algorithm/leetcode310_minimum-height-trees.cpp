#include <unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;
class Solution {
	unordered_map<int,unordered_set<int>> g;
	vector<int> vertex;
	queue<int> q;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(auto& e : edges)
        {
        	g[e[0]].insert(e[1]);
        	g[e[1]].insert(e[0]);
        }
        bool visited[n];
        bool outSide[n];//是最外围的节点？是最外围的，不用从他开始BFS，高度肯定不是最小的
        memset(outSide, 0, sizeof(outSide));
        int minh = INT_MAX, h = 0;
        for(int i = 0; i < n; i++)
        {
            if(minh > 2 && outSide[i])
                continue;
        	memset(visited, 0, sizeof(visited));
        	h = 0;
        	visited[i] = true;
        	q.push(i);
        	BFS(h,visited,outSide);
        	if(h < minh)
        	{
        		minh = h;
        		vertex.clear();
        		vertex.push_back(i);
        	}
        	else if(h == minh)
        		vertex.push_back(i);
        }
        return vertex;
    }

    void BFS(int& h, bool* visited, bool* outSide)
    {
    	int tp, size;
        unordered_set<int> lastLv;
    	while(!q.empty())
    	{
    		size = q.size();
            lastLv.clear();
    		while(size--)
    		{
	    		tp = q.front();
	    		q.pop();
	    		for(const int& id : g[tp])
	    		{
	    			if(!visited[id])
	    			{
	    				q.push(id);
	    				visited[id] = true;
                        lastLv.insert(id);
	    			}
	    		}
	    	}
	    	h++;
    	}
        for(auto& id : lastLv)
            outSide[id] = true;
    }
};
int main()
{
	Solution s;
	vector<vector<int>> v = {{1,0},{1,2},{1,3}};
	s.findMinHeightTrees(4,v);
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        int i, tp, size;
        unordered_map<int,unordered_set<int>> g;
        vector<int> vertex;
        queue<int> q;
        for(auto& e : edges)
        {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        for(i = 0; i < n; i++)
            if(g[i].size() == 1)//出入度1
                q.push(i);
        while(n > 2)
        {
            size = q.size();
            n -= size;//剩余的节点个数n
            while(size--)
            {
                tp = q.front();
                q.pop();
                for(const int& id : g[tp])
                {
                    g[id].erase(tp);
                    if(g[id].size() == 1)
                        q.push(id);
                }
            }
        }

        while(!q.empty())
        {
            vertex.push_back(q.front());
            q.pop();
        }
        return vertex;
    }
};