
#include "netlib/curlBase.h"
#include "regex/regexBase.h"



int main (int argc, char const *argv[])
{
	
	string url="news.163.com";
	CNetBase *netSpider=new CNetBase();
	
	vector<string> res;
	CRegex *reg=new CRegex();
	
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
	
	for(auto i=res.begin();i!=res.end();i++)
		cout <<"match [ " << *i << " ]" <<endl;
	/* code */
	return 0;
}


