class UndergroundSystem {
	map<vector<string>,vector<int>> station_time_n;//2个string（起点，终点）；2个int（总时间，人数）
	map<int, pair<string,int>> id_startStation;// 乘客id；（起点，出发时刻）
	vector<string> s;
public:
    UndergroundSystem() { }
    
    void checkIn(int id, string stationName, int t) {
        id_startStation.insert({id,make_pair(stationName,t)});// 乘客id；（起点，出发时刻）
    }
    
    void checkOut(int id, string stationName, int t) {
    	s = {id_startStation[id].first, stationName};//起点，终点
    	if(!station_time_n.count(s))
        	station_time_n.insert({s,{t-id_startStation[id].second,1}});
        else
        {
        	station_time_n[s][0] += t-id_startStation[id].second;
        	station_time_n[s][1] += 1;
        }
       id_startStation.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
    	s = {startStation, endStation};
        return station_time_n[s][0]/double(station_time_n[s][1]);
    }
};

class UndergroundSystem {
    unordered_map<string, unordered_map<string,pair<int,int>>> Station_time_n;// 起点：终点；2个int（总时间，人数）
    unordered_map<int, pair<string,int>> id_startStation_t;// 乘客id，（起点，出发时刻）
    string startStation;
    int time;
public:
    UndergroundSystem() { }
    
    void checkIn(int id, string stationName, int t) {
        id_startStation_t[id].first = stationName;//  乘客id，（起点，出发时刻）
        id_startStation_t[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        startStation = id_startStation_t[id].first;
        time = t-id_startStation_t[id].second;
        Station_time_n[startStation][stationName].first += time;
        Station_time_n[startStation][stationName].second += 1;
        id_startStation_t.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return Station_time_n[startStation][endStation].first/double(Station_time_n[startStation][endStation].second);
    }
};