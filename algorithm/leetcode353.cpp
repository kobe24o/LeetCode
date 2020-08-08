class SnakeGame {
    vector<vector<int>> food;
    int m, n, i = 0, score = 0;
    int x = 0, y = 0;
    unordered_map<string, vector<int>> dir;
    deque<pair<int,int>> body;
    set<pair<int,int>> body_set;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->food = food;
        n = width;
        m = height;
        dir["R"] = {0,1};
        dir["D"] = {1,0};
        dir["U"] = {-1,0};
        dir["L"] = {0,-1};
        body.push_back({0,0});
        body_set.insert({0,0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        x += dir[direction][0];
        y += dir[direction][1];
        if(!(x>=0 && x<m && y>=0 && y<n)) 
            return -1;//出界
        if(i < food.size() && x == food[i][0] && y == food[i][1])
        {   //吃到食物
            body.push_front({x, y});
            body_set.insert({x, y});
            i++;
            score++;
        }
        else//没吃到
        {
            pair<int,int> tail = body.back();
            body_set.erase(tail);
            body.pop_back();
            body.push_front({x, y});
            if(body_set.count({x,y}))
                return -1;
            body_set.insert({x,y});
        }
        return score;
    }
};