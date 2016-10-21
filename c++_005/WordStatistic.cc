 ///
 /// @file    WordStatistic.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-21 13:42:37
 ///

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::stringstream;
using std::ostringstream;
using std::istringstream;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::vector;

class WordStatistic
{
public:
	void read_file(string filename);
	void write_file(string filename);
private:
	vector<string> _iword;
	vector<string> _oword;
};

void WordStatistic::read_file(string filename)
{
	ifstream ifs(filename);
	string line;
	while(getline(ifs,line))
	{
		istringstream iss(line);
		string word;
		while(iss >> word)
		{
			_iword.push_back(word);
		}
	}
	ifs.close();
    cout<< "read finish"<<endl;
}
void WordStatistic::write_file(string filename)
{
	ofstream ofs(filename);
	char flag='0';
	string word;
	unsigned ifrequence;
	ostringstream oss;
	for(auto & ielem : _iword)
	{
 //   cout<< ielem<<endl;
		for(auto & oelem : _oword)
           //  cout<< oelem<<endl;
		{
			istringstream iss(oelem);
			iss>>word>>ifrequence;
		    cout<<word<<"frequence"<<ifrequence<<endl;
            if(!word.compare(ielem))
			{
				ifrequence++;
				flag='1';
				break;
			}
		}
        cout<<flag<<"here"<<endl;
		if('1'==flag){
			flag='0';
            continue;
		}else
		{
			oss<<ielem<<1<<endl;
			word=oss.str();
			_oword.push_back(word);
		}
	}
	for(auto & elem : _oword)
	{
    cout<< elem<<endl;
		ofs<<elem;
	}
	ofs.close();
}
int main(void)
{
	WordStatistic letgo;
    string read_file_name="The_Holy_Bible.txt";
    string write_file_name="111.txt";
    letgo.read_file(read_file_name);
    letgo.write_file(write_file_name);
}
