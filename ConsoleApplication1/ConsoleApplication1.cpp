#include <iostream>
#include <vector>
#include "Function.h"
#include "Container.h"
#include "ConsoleApplication1.h"
using namespace std;
int main()
{
    Container* container = new Container();
    container->createNS("ns1");
    container->createNS("ns2");
    Namespace& ns1 = container->getNS(0);
    Namespace& ns2 = container->getNS(1);

    vector<Function*> funcs1;
    Function* func = new Function("funcname1", "a");
    funcs1.emplace_back(func);
    Function* func2 = new Function("funcname2", "b");
    funcs1.emplace_back(func2);
    Function* func3 = new Function("funcname3", "c");
    funcs1.emplace_back(func3);
    Function* func4 = new Function("funcname4", "d");
    funcs1.emplace_back(func4);

    vector<Field*> fields1;
    Field* field = new Field("fieldname1", "aa");
    fields1.emplace_back(field);
    Field* field2 = new Field("fieldname2", "bb");
    fields1.emplace_back(field2);
    Field* field3 = new Field("fieldname3", "cc");
    fields1.emplace_back(field3);
    Field* field4 = new Field("fieldname4", "dd");
    fields1.emplace_back(field4);

    //Создание класса с пустыми методами и полями
    MyClass* myClass = new MyClass("class1", funcs1, fields1);
    ns1.addClass(myClass);

    vector<Function*> funcs2;
    Function* func11 = new Function("funcname1", "a");
    funcs2.emplace_back(func11);
    Function* func22 = new Function("funcname2", "b");
    funcs2.emplace_back(func22);
    Function* func33 = new Function("funcname3", "c");
    funcs2.emplace_back(func33);

    vector<Field*> fields2;
    Field* field11 = new Field("fieldname1", "aa");
    fields2.emplace_back(field11);
    Field* field22 = new Field("fieldname2", "bb");
    fields2.emplace_back(field22);
    Field* field33 = new Field("fieldname3", "cc");
    fields2.emplace_back(field33);

    MyClass* myClass2 = new MyClass("class2", funcs2, fields2);
    ns1.addClass(myClass2);
    myClass->extend(myClass2);

    container->getNS(0).print();
 

}
