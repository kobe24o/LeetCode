class TwoSum {
	unordered_map<int,int> m;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
    	m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
    	for(auto it = m.begin(); it != m.end(); ++it)
    	{
    		if((it->first*2 == value && it->second>=2)
    			||(it->first*2 != value && m.find(value-it->first)!=m.end()))
    			return true;
    	}
    	return false;
    }
};