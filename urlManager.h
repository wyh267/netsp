#ifndef _URLMANAGER_H_
#define _URLMANAGER_H_


#include <map>
#include <vector>



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
			
			if(m_urls_map.find(*i) == m_urls_map.end()){
				m_urls_map[*i]=1;
			}
			
			cout <<"map [ "  << *i << " ] count : " << m_urls_map[*i] << endl;
			
		}
		
		return true;
		
	}
	
	
	int getSize(){
		
		return m_urls_map.size();
	}
	
	
private:
	
	map<string,int> m_urls_map; //等待处理的url列表,后一个参数表示已经存在此链接



};





#endif

