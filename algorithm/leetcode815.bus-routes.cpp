class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T)//哈哈，又被坑了
            return 0;
        unordered_map<int,unordered_set<int>> station_line;//站点，线路
        unordered_map<int,unordered_set<int>> line_station;//线路，站点
        queue<int> q;//线路队列
        int n = routes.size(), line, station, step = 1, size;
        unordered_set<int> visitedStation;
        unordered_set<int> visitedLine;
        for(int i = 0, j; i < n; ++i)
        {
        	for(j = 0; j < routes[i].size(); ++j)
        	{
        		station_line[routes[i][j]].insert(i);
        		line_station[i].insert(routes[i][j]);
        		if(routes[i][j] == S)
        		{
        			q.push(i);//起点站的线路，都放进队列
        			visitedStation.insert(S);
        			visitedLine.insert(i);
        		}
        	}
        }
        while(!q.empty())
        {
        	size = q.size();
        	while(size--)
        	{
        		line = q.front();
        		q.pop();
        		if(line_station[line].count(T))
        			return step;//线路包含终点，返回
        		for(auto st = line_station[line].begin(); st != line_station[line].end(); ++st)
        		{	//查找这条线路经过的所有站
        			if(!visitedStation.count(*st))
        			{	//没访问过的站
        				visitedStation.insert(*st);
        				for(auto l = station_line[*st].begin(); l != station_line[*st].end(); ++l)
        				{	//这个站的所有未访问线路
        					if(!visitedLine.count(*l))
        					{
        						q.push(*l);
        						visitedLine.insert(*l);
        					}
        				}
        			}
        		}
        	}
        	step++;
        }
        return -1;
    }	
};