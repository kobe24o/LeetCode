class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.empty()) return 0;
    	int i, n = position.size();
    	vector<vector<int>> car(n,vector<int>(2));
    	for(i= 0; i < n; i++)
    	{
    		car[i][0] = target-position[i];
    		car[i][1] = speed[i];
    	}
    	sort(car.begin(), car.end(), [&](auto a, auto b){
    		return a[0] < b[0];//距离近的先处理
    	});

    	int block = 1;//车队数量
    	double maxtime, time;
        maxtime = car[0][0]/double(car[0][1]);
    	//距离近的车按自己速度到达终点的时间
    	for(i = 1; i < n; ++i)
    	{
    		time = car[i][0]/double(car[i][1]);
    		//距离远的车的时间
    		if(maxtime < time)//距离远的车追不上前车
    		{
                block++;
                maxtime = time;
            }
    	}
    	return block;
    }
};