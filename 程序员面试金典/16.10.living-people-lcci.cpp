struct cmp1
{
	operator()(vector<int>& a, vector<int> &b)
	{
		return a[0] > b[0];
	}
};
struct cmp2
{
	operator()(vector<int>& a, vector<int> &b)
	{
		return a[1] > b[1];
	}
};
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
    	priority_queue<vector<int>,vector<vector<int>>,cmp1> baby;
    	priority_queue<vector<int>,vector<vector<int>>,cmp2> people;
    	vector<int> mostP_year(2,0);
    	int time = 2000, maxPeople = 0;
    	for(int i = 0; i < birth.size(); ++i)
    	{
    		baby.push({birth[i],death[i]});
    		time = min(time, birth[i]);
    	}
    	while(!baby.empty() || !people.empty())
    	{
    		while(!baby.empty() && baby.top()[0]==time)
    		{
    			people.push(baby.top());
    			baby.pop();
    		}
    		if(people.size() > mostP_year[0])
    		{
    			mostP_year[0] = people.size();
    			mostP_year[1] = time;
    		}
    		

    	}
    }
};