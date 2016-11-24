///
/// @file    homework_search.cc
/// @author  ToTYToT(hongzimeng@foxmail.com)
/// @date    2016-11-02 10:07:18
///

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
using std::istringstream;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::cin;
class TextQuery
{
public:
    void readFile(const string filename);
    void query(const string & word);
    void display(const string & word);
private:
    vector<string> _vecLines;
    map<string, set<unsigned> > _mapWord2Line;
    map<string, unsigned> _mapWordFreq;
};
void TextQuery::readFile(const string filename)
{
    ifstream ifs(filename.c_str());
    if(!ifs.good())
    {
        cout << "ifstream open error!" << endl;
        return;
    }
    string line;
    unsigned i=0;
    while(getline(ifs, line))
    {
        _vecLines.push_back(line);
        istringstream iss(line);
        string word;
        while(iss >> word)
        {
            ++_mapWordFreq[word];
            _mapWord2Line[word].insert(i);
        }
        ++i;
    }
    ifs.close();
}

void TextQuery::query(const string & word)
{
    map<string,unsigned>::iterator fit;
    fit=_mapWordFreq.find(word);
    if(fit==_mapWordFreq.end())return;
    map<string,set<unsigned> >::iterator lit;
    lit=_mapWord2Line.find(word);
    cout<<word<<" occurs   "<<fit->second<<" times."<<endl;
    set<unsigned>::iterator sit;
    for(sit=lit->second.begin();sit!=lit->second.end();++sit)
    {
        cout<<"(line "<<*sit+1<<") "<<_vecLines[*sit]<<endl;
    }
}
//void display(const string & word)
//{
//
//}
int main(int argc, char *argv[])
{
    //string s1 = "second";
    if(argc!=2)
    {
        cout<<"the file name "<<endl;
        return -1;
    }
    TextQuery tq;
    //tq.readFile("china_daily.txt");
    tq.readFile(argv[1]);
    string s;
    while(cin>>s){
    //tq.readFile(s);
    tq.query(s);
    }
 //   tq.display();

    return 0;
}
