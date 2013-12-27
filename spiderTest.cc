
#include "netlib/curlBase.h"
#include "regex/regexBase.h"
#include "urlManager.h"


int main (int argc, char const *argv[])
{
	
	string url="news.163.com";
	CNetBase *netSpider=new CNetBase();
	
	vector<string> res;
	CRegex *reg=new CRegex();
	
	CUrlManager *m=new CUrlManager();
	
	if(netSpider->getUrl(url) == true)
	{
		cout << " String Len : " << netSpider->getContent().size() << endl;
	}else{
		cout << "Error to get Url : " << url << endl;
		return 0;
	}
	
	
	if(reg->parseURL(netSpider->getContent())==true)
	{
		res=reg->getUrls();
		
	}else
	{
		cout << "Not Match" << endl;
		return 0;
	}
	
	reg->releaseRes();
	
	m->insertToMap(res);
	
	cout << " RES SIZE : " << res.size() << endl;
	cout << " MAP SIZE : " << m->getSize() << endl;
	
	
	//for(auto i=res.begin();i!=res.end();i++)
	//	cout <<"match [ " << *i << " ]" <<endl;
	/* code */
	return 0;
}


