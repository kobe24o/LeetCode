class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0, n = start.size();
        while (i < n && j < n)
        {
        	while(i < n && start[i]=='X')
        		i++;
        	while(j < n && end[j]=='X')
        		j++;
        	if(start[i] != end[j])
        		return false;
        	if(start[i] == 'L' && i < j)//L左移后，j 应该 <= i
        		return false;
        	if(start[i] == 'R' && i > j)//R右移后，j 应该 >= i
        		return false;
            i++;
            j++;
        }
        return true;
    }
};