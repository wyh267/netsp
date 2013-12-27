#include "curlBase.h"

//Test case
int main (int argc, char const *argv[])
{
	string url="news.163.com";
	string url2="www.sina.com.cn";
	CNetBase *net=new CNetBase();
	//CNetBase *net1=new CNetBase();
	
	if(net->getUrl(url) == true)
	{
		cout << " String Len : " << net->getContent().size() << endl;
	}
	if(net->getUrl(url2) == true)
	{
		cout << " String Len : " << net->getContent().size() << endl;
	}
	
	return 0;
}