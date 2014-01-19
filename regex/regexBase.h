#ifndef _REGEX_H_
#define _REGEX_H_

/**********************

正则表达式封装

***********************/

#include <iostream>
#include <string>
#include <regex>
#include <vector>



using namespace std;


namespace netspider
{

	class CRegex{

	public:
	
		CRegex(){}
	
		~CRegex(){}
	
	
	
		//
		// 解析页面的url地址
		// 输入 : 页面内容
		// 输出 : 有合法的url返回true,没有返回false
		//
		bool parseURL(string contents){
			const regex pattern("(http|https)://([\\w\\./]*\\.htm)");
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
	
	
		//
		// 获取url地址列表
		// 输入 : 无
		// 输出 : 返回全部url地址
		//
		vector<string> getUrls(){
			return m_urls;
		}
	
	
	
		//
		// 释放url地址列表
		//
		//
		//
		bool releaseRes(){
		
			for(vector<string>::iterator i=m_urls.begin();i!=m_urls.end();++i)
			{
				string().swap(*i);
			}
			m_urls.clear();
			return true;
		
		}
	
	private:
	
		vector<string> m_urls;   //url地址列表



	};

}


#endif
