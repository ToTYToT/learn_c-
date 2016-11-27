 ///
 /// @file    test.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-26 21:42:35
 ///
 
//#include "_THE_INFO_OF_RUN.h"
#if 0
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <unordered_map>
using std::string;
using std::map;
using std::vector;
using std::pair;
using std::unordered_map;
int main()
{
	std::unordered_map<string,int> dict = {{ "one",1}, { "two",2}};
	//unordered_map["three"]=4;
	unordered_map <string, vector<pair<int, double> > > _InvertIndexTable();
	vector<pair<int,double> > a;
	string b("hello");
	a.push_back(std::make_pair(4,5.5));
	unordered_map<string,vector<pair<int,double> > >::iterator it;
	it=_InvertIndexTable.begin();
	(*it).first="hello";
	(*it).second.push_back(4,5.5);
//	_InvertIndexTable["hello"];
	//_InvertIndexTable["hello"].push_back(std::make_pair(4,5.5));
	//_InvertIndexTable.insert({b,a});
}
#endif
#if 1
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>
int main()
{
    double xxxx=log10(8)/log10(2);
    std::cout<<xxxx<<std::endl;
	std::unordered_map<char, int> letter_counts {{'a', 27}, {'b', 3}, {'c', 1}};
	std::unordered_map<std::string,std::vector<std::pair<int,double> > > _letter_counts;
	std::unordered_map<std::string,std::unordered_map<int,double> > __letter_counts;
    __letter_counts["hello"][1]=5.5;
    std::cout<<__letter_counts["hello"][1]<<std::endl;
	_letter_counts["heel"].push_back(std::make_pair(4,5.5));

	std::cout << "initially:\n";
	for (const auto &pair : letter_counts) {
		std::cout << pair.first << ": " << pair.second << '\n';
	}

	letter_counts['b'] = 42;  // update an existing value
	letter_counts['x'] = 9;  // insert a new value

	std::cout << "after modifications:\n";
	for (const auto &pair : letter_counts) {
		std::cout << pair.first << ": " << pair.second << '\n';
	}

	// count the number of occurrences of each word
	// (the first call to operator[] initialized the counter with zero)
	std::unordered_map<std::string, size_t>  word_map;
	for (const auto &w : { "this", "sentence", "is", "not", "a", "sentence",
			"this", "sentence", "is", "a", "hoax"}) {
		++word_map[w];
	}

	for (const auto &pair : word_map) {
		std::cout << pair.second << " occurrences of word '" << pair.first << "'\n";
	}
}
#endif

#if 0
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <vector>
#include <string>
using std::vector;

void printdir(char* path,int width)
{
    DIR* dir;
    dir=opendir(path);
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
            printf("%*s%s\n",width,"",p->d_name);
            if(p->d_type ==4)
            {
                sprintf(buf,"%s%s%s",path,"/",p->d_name);//拼接路径
                printdir(buf,width+4);
            }
        }
    }
    closedir(dir);
}


int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        printf("error args\n");
        return -1;
    }
    printf("%s\n",argv[1]);
    printf("------------------------------\n");
    printdir(argv[1],0);
    vector<std::string> a;
    char buf[100]="aaa";
    a.push_back(buf);
    return 0;
}
#endif

