class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
    	vector<int> decimal;
    	int num;
    	for(string& p : prices)
    	{
    		target -= stoi(p);
    		num = stoi(p.substr(p.size()-3));
    		if(num != 0)
    			decimal.push_back(num);//有小数的
    	}
    	if(target > decimal.size())//全部向上取整都不够的
    		return "-1";
    	if(target < 0)//全部向下取整，和还超过target
    		return "-1";
    	sort(decimal.rbegin(), decimal.rend());//大的在前面（靠近1）
    	int error = 0;
    	for(int i = 0; i < decimal.size(); ++i)//所有非0的小数都要取整
    	{
    		if(target > 0)
    			error += 1000-decimal[i],//向上取整
    			target--;
    		else if(target == 0)//不需要了，全部舍弃小数
    			error += decimal[i];
    	}
    	char ch[8];//最多500，3位+.1位+3小数+\0 1位 = 8
    	sprintf(ch, "%.3f", double(error)/1000);
        return string(ch);
    }
};