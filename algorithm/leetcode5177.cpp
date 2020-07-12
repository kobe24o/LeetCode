class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string,string> m;
        m["Jan"]="01";
        m["Feb"]="02";
        m["Mar"]="03";
        m["Apr"]="04";
        m["May"]="05";
        m["Jun"]="06";
        m["Jul"]="07";
        m["Aug"]="08";
        m["Sep"]="09";
        m["Oct"]="10";
        m["Nov"]="11";
        m["Dec"]="12";
        int day = 0, month = -1, year = 0, i = 0;
        string t;
        while(isdigit(date[i]))
            day = day*10+date[i++]-'0';//天数
        while(date[i] != ' ')
            i++;
        i++;
        while(isalpha(date[i]))
            t += date[i++];//月份的字符串
        i++;
        while(i < date.size())
            year = year*10+date[i++]-'0';//年
        return to_string(year)+"-"+m[t]+"-"+(day>=10 ? to_string(day):("0"+to_string(day)));
    }   
};
