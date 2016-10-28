 ///
 /// @file    createXML.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-27 20:56:18
 ///
 
#include "tinyxml2.h"  
#include <stdlib.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using namespace tinyxml2;  

int createXML(const char* xmlPath)
{
    const char* declaration ="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
    XMLDocument doc;
    doc.Parse(declaration);//会覆盖xml所有内容

    //添加申明可以使用如下两行
    //XMLDeclaration* declaration=doc.NewDeclaration();
    //doc.InsertFirstChild(declaration);

    XMLElement* root=doc.NewElement("DBUSER");
    doc.InsertEndChild(root);

    return doc.SaveFile(xmlPath);
}
