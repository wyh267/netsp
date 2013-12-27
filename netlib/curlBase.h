#ifndef _CURLBASE_H_
#define _CURLBASE_H_


#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class CNetBase {
	
public:
	CNetBase(){
		m_init=0;
		m_offset=0;
		m_contents="";
		curl = curl_easy_init();        //初始化一个CURL类型的指针
	}
	
	~CNetBase(){
		//m_contents.~string();
		//free(p_data);
	}
	
	
	
	//
	// 写入到内存中，
	// 参数 : 数据指针，数据长度
	//
	bool writeToSram(char *ptr,int size){
		
		bool res=false;
		//cout << "size : " << size << endl;
		if(m_init==0){
			p_data=(char *)malloc(size);
			m_init++;
		}else{
			p_data=(char *)realloc((void *)p_data,size);
		}
		if(p_data!=NULL){
			//cout <<"data addr : " << hex << &p_data[0] << endl;
			memcpy((p_data+m_offset),ptr,size);
			m_offset+=size;
			res=true;
		}
		return res;
	}
	
	
	//
	// 写入到字符串中，
	// 参数 : 数据指针，数据长度
	//
	bool writeToString(char *ptr,int size){
		//cout << size << endl;
		string content;
		content.assign(ptr,size);
		m_contents+=content;
		return true;
	}
	
	//
	// 测试内存数据是否正确
	//
	//
	void testRamData(){
		
		for(int i=0;i<m_offset;i++){
			;//cout << p_data[i] ;
		}
		cout << m_contents << endl;
		
	}
	
	//
	// 下载网页
	// 参数 : url地址
	// 返回 : 成功或者失败
	bool getUrl(string url){
	    
	    resetStatus();
	    if(curl!=NULL)
	    {
	        //设置curl选项. 其中CURLOPT_URL是让用户指 定url. url中存放的命令行传进来的网址
	        curl_easy_setopt(curl, CURLOPT_URL,url.c_str());        
	        //设置回调函数
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CNetBase::write_data);  
			//设置特殊参数，实际传入的是本类的实例
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)this);
			//开始执行操作
		    res = curl_easy_perform(curl);
			if(res == 0){
				cout << "Get URL  : " << url << " Success" << endl;
				//curl_easy_cleanup(curl);
				return true;
			}else{
				cout << "Error To Get URL : " << url << endl;
				return false;
			}
			
	    }
		return false;	
	}


	//
	// 获取内容
	// 参数 : 无
	// 返回 : 上次抓取的内容
	string getContent(){
		return m_contents;
	}



	//
	// 清除curl操作
	//
	//
	bool cleanCrul(){
		
		//操作完成
		curl_easy_cleanup(curl);
		
		return true;
	}

	//
	//收到数据,最后一个参数是本类的实例
	//写入到内存中
	//
	static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)  
	{
		CNetBase *p=(CNetBase *)(stream);
	    //cout << " write data...."  << size*nmemb << "m_init "<< p->m_init <<"\n" << endl;
		if(p->writeToString((char *)ptr,size*nmemb))
			return size*nmemb;
	    return -1;
	}
	
private:
	int m_init;
	char *p_data;  	//内存数据指针地址
	int m_offset; 	//偏移量(数据区长度)
	string m_contents;	
    CURL *curl;             //定义CURL类型的指针
	CURLcode res;           //定义CURLcode类型的变量，保存返回状态码



	//
	// 重置变量
	//
	//
	void resetStatus(){
		m_init=0;
		m_offset=0;
		string().swap(m_contents);
		m_contents="";
	}

};





#endif