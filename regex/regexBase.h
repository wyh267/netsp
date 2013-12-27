

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
		const std::regex pattern("(http|https)://([\\w\\./]*\\.(html|htm|aspx|asp|php|jsp))");
		//定义结果
		std:: match_results<std::string::const_iterator> result;
		//开始匹配url
		const std::sregex_token_iterator end;  
		for (std::sregex_token_iterator i(contents.begin(),contents.end(), pattern); i != end ; ++i)
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
	
	
private:
	
	vector<string> m_urls;



};