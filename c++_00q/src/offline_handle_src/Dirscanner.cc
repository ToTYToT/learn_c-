 ///
 /// @file    Dirscanner.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-26 14:49:39
 ///
 
#include "_THE_INFO_OF_RUN.h"
#include "Dirscanner.h"
#include "Configuration.h" 
namespace T520
{
Dirscanner::Dirscanner(Configuration &conf)
:_conf(conf)
{
	_THE_INFO_OF_RUN;
	createFiles(_conf.getConfigMap()["dataSource.path"]);
}
vector<string> Dirscanner::getFiles()
{
	_THE_INFO_OF_RUN;
	//for(auto & elem : _vecFilesfiles)
	//	cout<<elem<<endl;
	return _vecFilesfiles;
}
void Dirscanner::createFiles(const string& dirname)
{
	_THE_INFO_OF_RUN;
	DIR* dir;
	dir=opendir(dirname.c_str());
	if(NULL==dir)
	{
		perror("opendir");
		return;
	}
	struct dirent* p;
	char buf[512]={0};
	while((p=readdir(dir)))
	{
		if(!strcmp(p->d_name,".") || !strcmp(p->d_name,".."))
		{
		}else{
			if(p->d_type ==4)
			{
				sprintf(buf,"%s%s%s",dirname.c_str(),"/",p->d_name);
				createFiles(buf);
				//traverse(buf);
			}else
			{
				sprintf(buf,"%s%s%s",dirname.c_str(),"/",p->d_name);
				_vecFilesfiles.push_back(buf);
			}
		}
	}
	closedir(dir);
}
}
//using namespace T520;
//int main(void)
//{
//	Configuration conf("../../conf/myconf.conf");
//	Dirscanner dir(conf);
//	dir();
//	dir.files();
//}
