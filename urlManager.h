#ifndef _URLMANAGER_H_
#define _URLMANAGER_H_


#include <map>
#include <vector>
#include <iostream>
#include <string>

#include "netlib/curlBase.h"
#include "regex/regexBase.h"


using namespace std;


class CUrlManager{
public:
	CUrlManager(){}
	~CUrlManager(){}
	
	
	
	//
	// 插入url地址到待处理列表中
	// 输入 : url地址列表
	// 插入过程中有去重操作
	//
	bool insertToMap(vector<string> urls){
		
		for(vector<string>::iterator i=urls.begin();i!=urls.end();++i){
			
			
			if(m_urls_delete_map.find(*i) == m_urls_delete_map.end() && m_urls_map.find(*i) == m_urls_map.end())
			{
				
				m_urls_map[*i]=1;
				
			}
			
			
			
			//cout <<"map [ "  << *i << " ] count : " << m_urls_map[*i] << endl;
			
		}
		
		return true;
		
	}
	
	
	int getSize(){
		
		return m_urls_map.size();
	}
	
	int getDeleteSize(){
		
		return m_urls_delete_map.size();
	}
	
	
	//
	// 启动蜘蛛采集
	// 输入 : 种子url
	// 输出 : 成功返回true
	//
	bool startManager(string seed_url){
		
		CNetBase *netSpider=new CNetBase();
		m_urls_map[seed_url]=1;
		vector<string> res;
		CRegex *reg=new CRegex();
		
		
		while(m_urls_map.size()>0)
		{
			for(map<string,int>::iterator it=m_urls_map.begin();it != m_urls_map.end();)
			{
				if(netSpider->getUrl((*it).first) == true)
				{
					cout << " String Len : " << netSpider->getContent().size() << endl;
					m_urls_delete_map[(*it).first]=1;
					it=m_urls_map.erase(it);
					
					if(reg->parseURL(netSpider->getContent())==true)
					{
						res=reg->getUrls();
						reg->releaseRes();			
						insertToMap(res);
		
					}else
					{
						cout << "Not Match" << endl;
					
					}
					//cout << " RES SIZE : " << res.size() << endl;
					cout << " MAP SIZE : " << getSize() << endl;
					cout << " DEL SIZE : " << getDeleteSize() << endl;
					res.clear();
				}
				else{
					cout << "Error to get Url : " << (*it).first << endl;
					it++;
				}
			}
		}
			
		cout << "Finish .... " << endl;
		return true;
	
		
		
	}
	
private:
	
	map<string,int> m_urls_map; //等待处理的url列表,后一个参数表示已经存在此链接
	map<string,int> m_urls_delete_map;


};





#endif

