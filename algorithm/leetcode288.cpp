class ValidWordAbbr {
	unordered_map<string, int> m;
    unordered_set<string> dict;
	string key;
public:
    ValidWordAbbr(vector<string>& dictionary) {
    	for(auto& d : dictionary)
    	{
            if(d.size()<=2)
                continue;
            m[getkey(d)]++;
            dict.insert(d);
        }
    }
    
    bool isUnique(string word) {
        if(word.size() <= 2)
            return true;
    	key = getkey(word);
    	if((dict.count(word) && (m[key] == 1)) || m.find(key) == m.end())
    		return true;
    	else
    		return false;
    }
    string getkey(string& word)
    {
    	key = word[0]+to_string(word.size()-2)+word[word.size()-1];
    	return key;
    }
};