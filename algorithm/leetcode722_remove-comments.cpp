class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
    	bool foundBlock = false;//找到多行注释块
    	bool foundlineCom = false;//单行注释块
    	int i, j;
    	bool flag = true;
    	string contiStr;//多行注释块删除后，其前后需要拼接，存储前面部分
        for(i = 0; i < source.size(); ++i)
        {
        	foundlineCom = false;//每次进入下一行，其为false
        	for(j = 0; j < source[i].size(); ++j)
        	{
        		if(!foundBlock && !foundlineCom)
        		{
        			if(source[i].substr(j,2) == "//")
        				foundlineCom = true;
        			else if(source[i].substr(j,2) == "/*")
        				foundBlock = true;	
        		}

        		if(foundlineCom)
        		{
        			source[i].erase(j);
        			break;//如果是单行注释，直接删除到末尾，跳到下一行
        		}
        		else if(foundBlock)//是多行注释
        		{
        			if(flag)//先删除2个字符 /*，避免 /*/ 出错
        			{
        				source[i].erase(j,2);
        				j--;//后面要++,先--，避免跳过字符
        				flag = false;
        				continue;
        			}
        			if(source[i].substr(j,2) == "*/")
        			{	//找到多行注释结束标志
        				source[i].erase(j,2);//删除*/
        				foundBlock = false;//结束
        				source[i] = contiStr+source[i];//拼接多行注释块前面的字符
        				j += contiStr.size()-1;//调整 j, 继续后面处理
        				contiStr = "";
        				flag = true;
        			}
        			else//正常删除中间字符
        			{
        				source[i].erase(j,1);
        				j--;
        			}
        		}

        	}
        	if(foundBlock)//如果是多行注释
        	{
        		contiStr += source[i];//前面的字符拼接起来
        		source[i].clear();//移到contiStr了，清空
        	}
        }
        for(int i = 0; i < source.size(); i++)
        	if(source[i].empty())
        	{	//删除空白行
        		source.erase(source.begin()+i);
        		i--;
        	}

        return source;
    }
};