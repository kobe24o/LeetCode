/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    unordered_set<string> visited;
public:
    void cleanRoom(Robot& robot) {
        visited.insert("0-0");//坐标访问过
        dfs(robot, 0, 0, 0);
    }
    void dfs(Robot& robot, int x, int y, int d)
    {
        robot.clean();
        int nx, ny, nd;
        string pos;
        for(int k = 1; k <= 4; ++k)
        {   
            robot.turnRight();//换方向      
            nd = (d+k)%4;
            nx = x + dir[nd][0];
            ny = y + dir[nd][1];
            pos = to_string(nx)+"-"+to_string(ny);
            if(visited.count(pos))//下一个位置访问过吗
                continue;
            if(robot.move())//没访问过，可以移动的话
            {
                visited.insert(pos);//访问了
                dfs(robot, nx, ny, nd);//移动
                robot.turnRight();//回溯，调转180度
                robot.turnRight();
                robot.move();//回退到原地
                robot.turnRight();//再转180把方向调到之前走的状态
                robot.turnRight();
            }
        }
    }
};