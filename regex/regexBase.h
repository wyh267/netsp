

#include <iostream>
#include <string>
#include <regex>
#include <vector>



using namespace std;
class CRegex{

public:
	
	CRegex(){}
	
	~CRegex(){}
	
	bool parseURL(string contents){
		const regex pattern("(http|https)://([\\w\\./]*\\.(html|htm|aspx|asp|php|jsp))");
		//定义结果
		match_results<string::const_iterator> result;
		//开始匹配url
		const sregex_token_iterator end;  
		for (sregex_token_iterator i(contents.begin(),contents.end(), pattern); i != end ; ++i)
		{
			//std::cout << *i << std::endl;
			m_urls.push_back(*i);
		}
		
		
		
		
		if(m_urls.size()>0)
			return true;
		
		return false;	   
		   
	}
	
	
	vector<string> getUrls(){
		return m_urls;
	}
	
	
	bool releaseRes(){
		
		for(vector<string>::iterator i=m_urls.begin();i!=m_urls.end();++i)
		{
			string().swap(*i);
		}
		m_urls.clear();
		return true;
		
	}
	
private:
	
	vector<string> m_urls;



};