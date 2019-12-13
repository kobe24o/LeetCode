class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1, count = 0, w = 0, p = 0;
        while(i <= j)
        {
        	while(j >= 0 && p < 2 && w+people[j] <= limit)
        	{
        		w += people[j];
        		++p;//一条船最多两人
        		--j;
        	}
        	while(i <= j && p < 2 && w+people[i] <= limit)
        	{
        		w += people[i];
        		++p;
        		++i;
        	}
        	count++;
        	p = 0;
        	w = 0;
        }
        return count;
    }
};