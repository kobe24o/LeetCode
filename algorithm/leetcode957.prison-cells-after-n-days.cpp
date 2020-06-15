class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    	int state = 0, nextstate = 0, i, gap;
    	for(i = 0; i < 8; i++)
    	{
    		if(cells[i])
    			state |= 1<<(i);//记录初始状态到int
    	}
    	unordered_map<int,int> rec;//状态，天数
        unordered_map<int,int> day_state;//天数,状态
    	rec[state] = 0;
        day_state[0] = state;
    	for(int day = 1; day <= N; day++)
    	{
    		for(i = 1; i < 7; i++)//两端为0，不用遍历
    		{
    			if( ( ((state>>(i-1))&1) && ((state>>(i+1))&1) ) 
    				|| ( ((state>>(i-1))&1)==0 && ((state>>(i+1))&1)==0 ) )
    				nextstate |= 1<<(i);//下一个状态
    		}
    		state = nextstate;
            day_state[day] = state;
    		if(rec.count(state))//找到了循环出现的状态
    		{
    			gap = day - rec[state];//周期间隔
    			break;
    		}
            rec[state] = day;
    		nextstate = 0;
    	}
    	//进入循环前有 rec[state] 天
    	//剩余的 天数 N-rec[state] 有多少个循环 (N-rec[state])/gap 个
    	//还剩余多少 N-rec[state] - (N-rec[state])/gap*gap
    	//加上 进入 循环前的 天数 rec[state]+N-rec[state]-(N-rec[state])/gap*gap
    	//最后的状态跟 那天的状态是一样的
    	state = day_state[rec[state]+N-rec[state]-(N-rec[state])/gap*gap];
    	vector<int> ans(8,0);
    	for(i = 1; i < 7; i++)
    	{
    		if((state>>i)&1)
    			ans[i] = 1;//转成数组答案
    	}
    	return ans;
    }
};