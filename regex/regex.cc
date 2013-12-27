#include <stdio.h>
#include <regex>
#include <string>
#include <vector>

#include "regexBase.h"

using namespace std;
int main(int argc, char** argv)
{
	vector<string> res;
	string ip="fffhttp://www.sina.com.cn/dds.htm RDDDFdsafahttp://www.143.com/rr.html";
    CRegex *reg=new CRegex();
	if(reg->parseURL(ip)==true)
	{
		res=reg->getUrls();
		
	}else
	{
		cout << "Not Match" << endl;
		return 0;
	}
	
	
	for(auto i=res.begin();i!=res.end();i++)
		cout <<"match [ " << *i << " ]" <<endl;
	
	
	return 0;
}