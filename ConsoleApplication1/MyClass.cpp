#include "MyClass.h"
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

void MyClass::setFuncVector(const vector<Function*> functionVector) {
    MyClass::funcVector = functionVector;
}

void MyClass::setFieldVector(const vector<Field*> fieldVector) {
    MyClass::fieldVector = fieldVector;
}


void MyClass::setName(string newName) {
    MyClass::name = newName;
}


const vector<Function*> MyClass::getFuncVector() const {
    return funcVector;
}

const vector<Field*> MyClass::getFieldVector() const {
    return fieldVector;
}
const string& MyClass::getName() const {
    return name;
}

MyClass::MyClass(string name, const vector<Function*> funcVector, const vector<Field*> fieldVector) : name(std::move(name)), funcVector(funcVector), fieldVector(fieldVector) {}

MyClass::MyClass(string name) : name(std::move(name)) {
    
}


void MyClass::addFunc(string funcName, string value) {
    Function* func = new Function(funcName, value);
    this->funcVector.push_back(func);
}

bool MyClass::rmFunc(int id) {
    if (id >= funcVector.size() || id < 0) {
        return false;
    }
    funcVector.erase(funcVector.begin() + id);
    return true;
}

void MyClass::addField(string fieldName, string value) {
    Field* field = new Field(fieldName, value);
    this->fieldVector.push_back(field);
}

bool MyClass::rmField(int id) {
    if (id >= fieldVector.size() || id < 0) {
        return false;
    }
    fieldVector.erase(fieldVector.begin() + id);
    return true;
}



bool MyClass::changeField(string newValue, int id) {
    if (id >= fieldVector.size() || id < 0) {
        return false;
    }
    fieldVector[id]->setValue(newValue);
    return true;
}

bool MyClass::changeFunc(string newValue, int id) {
    if (id >= funcVector.size() || id < 0) {
        return false;
    }
    funcVector[id]->setValue(newValue);
    return true;
}

bool MyClass::operator==(const MyClass& rhs) const {
    return name == rhs.name;
}

bool MyClass::operator!=(const MyClass& rhs) const {
    return name != rhs.name;
}

MyClass::~MyClass() {
    name.erase();
    funcVector.clear();
    funcVector.shrink_to_fit();
    fieldVector.clear();
    fieldVector.shrink_to_fit();
}

void MyClass::print() {
    int i = 0;
    int j = 0;
    cout << name << endl;
    cout << "Fields:" << endl;
    for (auto it = fieldVector.begin(); it != fieldVector.end(); ++it, ++i) {
        cout << "   " << i << ": ";
        auto curr = dynamic_cast<Field*>(*it);
        curr->print();
    }
    cout << "Functions:" << endl;
    for (auto it1 = funcVector.begin(); it1 != funcVector.end(); ++it1, ++j) {
        cout << "   " << j << ": ";
        auto curr = dynamic_cast<Function*>(*it1);
        curr->print();
    }
    if (parent != NULL) {
        cout << "Parent:" << parent->getName() << endl;
    }
    }

bool MyClass::canExtend(MyClass* myClass)
{
    bool res;
   // if (!this->getFuncVector().empty()) {
        vector<Function*> funcs1 = this->getFuncVector();
        vector<Function*> thisFuncs(funcs1.begin(), funcs1.end());

        //int i = 0;
        //int j = 0;
        //for (auto it1 = funcs1.begin(); it1 != funcs1.end(); ++it1, ++i) {
        //    cout << "   " << i << ": ";
        //    auto curr = dynamic_cast<Function*>(*it1);
        //    curr->print();
        //}
        //cout << endl;


        vector<Function*> funcs2 = myClass->getFuncVector();
        vector<Function*> extendFuncs(funcs2.begin(), funcs2.end());

     /*   for (auto it1 = funcs2.begin(); it1 != funcs2.end(); ++it1, ++j) {
            cout << "   " << j << ": ";
            auto curr = dynamic_cast<Function*>(*it1);
            curr->print();
        }*/

        sort(thisFuncs.begin(), thisFuncs.end());
        sort(extendFuncs.begin(), extendFuncs.end());
        res = std::includes(extendFuncs.begin(), extendFuncs.end(), thisFuncs.begin(), thisFuncs.end());
        cout << res << endl;
        thisFuncs.clear();
        thisFuncs.shrink_to_fit();
        extendFuncs.clear();
        extendFuncs.shrink_to_fit();
    //}
    //else res = true;
    return res;
}

bool MyClass::extend(MyClass* myClass)
{
    if (!canExtend(myClass)) {
        return false;
   }
    parent = myClass;
    return true;
}

void MyClass::deleteExtend()
{
    parent == NULL;
}

