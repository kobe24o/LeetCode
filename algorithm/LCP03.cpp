class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int ax = 0, by = 0, circle, px, py;
        unordered_map<int,unordered_set<int>> m;
        m[0].insert(0);
        for(int i = 0; i < command.size(); i++)
        {
        	if(command[i] == 'U')
        		by += 1;
        	else
        		ax += 1;
        	m[ax].insert(by);
        }
        circle = min(x/ax, y/by);
        px = x-ax*circle;
        py = y-by*circle;
        if(!m.count(px) || !m[px].count(py))
            return false;
        for(int i = 0; i < obstacles.size(); ++i)
        {
            if(obstacles[i][0] > x || obstacles[i][1] > y)
                continue;
            circle = min(obstacles[i][0]/ax, obstacles[i][1]/by);
            px = obstacles[i][0]-ax*circle;
            py = obstacles[i][1]-by*circle;
        	if(m.count(px) && m[px].count(py))
                return false;
        }
        return true;
    }
};