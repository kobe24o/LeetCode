class Solution {
	double r;
	double x, y;
	double cos_theta, sin_theta;
public:
    Solution(double radius, double x_center, double y_center) {
    	r = radius;
    	x = x_center;
    	y = y_center;
    }
    
    vector<double> randPoint() {
    	do
    	{
    		cos_theta = 2*(double)rand()/RAND_MAX - 1;
    		sin_theta = 2*(double)rand()/RAND_MAX - 1;
    	}
		while(sin_theta*sin_theta + cos_theta*cos_theta > 1);//在圆外
        return {x+r*cos_theta, y+r*sin_theta};
    }
};