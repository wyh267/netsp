#include "urlManager.h"





int main (int argc, char const *argv[])
{
	CUrlManager *m=new CUrlManager();
	vector<string> ss;
	ss.push_back("aaaaa");
	ss.push_back("bbb");
	ss.push_back("dddd");
	ss.push_back("aaaccaa");
	ss.push_back("aassaaa");
	ss.push_back("aaaaa");
	ss.push_back("bbb");
	
	m->insertToMap(ss);
	
	/* code */
	return 0;
}