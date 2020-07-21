class LogSystem {
	vector<long long> second = {12*31*24*3600, 31*24*3600, 24*3600, 3600, 60, 1}
public:
    LogSystem() {

    }
    
    void put(int id, string timestamp) {

    }
    
    vector<int> retrieve(string s, string e, string gra) {
    	//Year:Month:Day:Hour:Minute:Second
    }
    int timeToint(string& s, int g = 6)
    {	// 例如 2017:01:01:23:59:59
    	int Year = stoi(s.substr(0,4));
    	int Month = stoi(s.substr(5,2));
    	int Day = stoi(s.substr(8,2));
    	int Hour = stoi(s.substr(11,2));
    	int Minute = stoi(s.substr(14,2));
    	int Second = stoi(s.substr(17,2));
    	if(g==6)
    		return (Year-1999)*second[0]+Month*second[1]+Day*second[2]+Hour*second[3]+Minute*second[4]+Second*second[5];
    }	
};