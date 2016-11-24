 
#include "TextQuery.h"
#include "Query.h"
#include "WordQuery.h"
#include <iostream>
using std::cout;
using std::endl;


int main(void)
{
	TextQuery tq;
	tq.readFile("./data/data.txt");

	string s1 = "(fiery & bird)|wind";
    Query query1=Query("fiery");
    set<int>ret1=query1.doQuery(tq);
    showResult(tq,ret1);
    Query query2=~query1;
    set<int>ret2=query2.doQuery(tq);
    showResult(tq,ret2);
    Query query3=query2&query1;
    set<int>ret3=query3.doQuery(tq);
    showResult(tq,ret3);

	Query query = Query("fiery") & Query("bird") | Query("wind");

	set<int> ret = query.doQuery(tq);
	cout << "执行查询: " << query << endl; 

	showResult(tq, ret);
	return 0;
}
