class Solution {
public:
    vector<int> closestDivisors(int num) {
    	int product = num+1;
    	int a = sqrt(product);
    	while(a > 0 && product%a != 0)
    		a--;
    	int x1 = a, y1 = product/a;
    	product = num+2;
    	a = sqrt(product);
    	while(a > 0 && product%a != 0)
    		a--;
    	int x2 = a, y2 = product/a;
    	if(abs(x1-y1) < abs(x2-y2))
    		return {x1, y1};
    	return {x2, y2};
    }
};