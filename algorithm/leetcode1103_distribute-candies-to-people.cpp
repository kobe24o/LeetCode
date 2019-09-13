class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        for (int i = 0, candy = 1; i < num_people; ++i,++candy)
        {
        	if(candies >= candy)
        	{
        		ans[i] += candy;
        		candies -= candy;
        	}
        	else//不够了
        	{
        		ans[i] += candies;
        		break;
        	}
        	if(i == num_people-1)
        		i = -1;//这里注意是-1，不是0，后面还要++i
        }
        return ans;
    }
};