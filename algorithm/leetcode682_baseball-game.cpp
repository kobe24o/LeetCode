class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0, i, j;
        vector<int> score;
        for(string& op : ops)
        {
        	if(isdigit(op[0]) || op[0] == '-')//是数字
        		score.push_back(stoi(op));
        	else if(op == "C")
        		score.pop_back();
        	else if(op == "D")
        		score.push_back(2*score.back());
        	else if(op == "+")
        		score.push_back(score[score.size()-1]+score[score.size()-2]);
        }
        for(int& sc : score)
        	sum += sc;
        return sum;
    }
};