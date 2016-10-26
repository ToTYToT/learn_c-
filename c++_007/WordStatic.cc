///
/// @file    WordStatic.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2016-10-24 09:54:43
///

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;


struct Record
{
    string word;
    int cnt;
};

class WordStatic
{
    public:
    void readFile(const string & filename);
    void writeFile(const string & filename);
    private:
    vector<Record> _wordList;
};


void WordStatic::readFile(const string & filename)
{
    ifstream ifs(filename.c_str());
    if(!ifs.good())
    {
        cout << "ifstream open error!" << endl;
        return;
    }

    string line;
    while(getline(ifs, line))
    {
        istringstream iss(line);
        string word;
        while(iss >> word)
        {
            vector<Record>::iterator it;
            for(it = _wordList.begin();
            it != _wordList.end();
            ++it)
            {
                if(it->word == word)
                {
                    ++(it->cnt);
                    break;
                }
            }

            if(it == _wordList.end())
            {
                Record record;
                record.word = word;
                record.cnt = 1;
                _wordList.push_back(record);
            }
        }
    }
    ifs.close();

    //对词典中的单词进行排序
    //sort(_wordList.begin(), _wordList.end());
}


void WordStatic::writeFile(const string & filename)
{
    ofstream ofs(filename.c_str());
    if(!ofs.good())
    {
        cout << "ofstream open error!" << endl;
        return ;
    }

    for(auto & elem : _wordList)
    {
        ofs << elem.word << " " << elem.cnt << endl;
    }

    ofs.close();
}


int main(void)
{
    WordStatic ws;
    ws.readFile("dict.txt");
    ws.writeFile("dict.dat");

    return 0;
}

