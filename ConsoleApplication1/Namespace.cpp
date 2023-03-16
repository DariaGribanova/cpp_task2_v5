#include "Namespace.h"
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
MyClass* Namespace::rmCLass(int id) {
    MyClass* res = classVector[id];
    classVector.erase(classVector.begin() + id);
    return res;
}

void Namespace::addClass(MyClass* myClass) {
    classVector.push_back(myClass);
}

Namespace::Namespace(string name, const vector<MyClass*>& classVector) : name(std::move(name)),
classVector(classVector) {}

Namespace::~Namespace() {
    name.erase();
    classVector.clear();
    classVector.shrink_to_fit();
}

bool Namespace::operator==(const Namespace& rhs) const {
    return name == rhs.name;
}



bool Namespace::operator!=(const Namespace& rhs) const {
    return rhs.name != this->name;
}


Namespace::Namespace(string name) : name(std::move(name)) {

}

void Namespace::print() {
    int i = 0;
    cout << name << endl;
    cout << "Classes:" << endl;
    for (auto it = classVector.begin(); it != classVector.end(); ++it, ++i) {

        cout << "   " << i << ": ";
        auto curr = dynamic_cast<MyClass*>(*it);
        curr->print();
        cout << endl;
    }
}

MyClass*& Namespace::get(int id) {
    return classVector[id];
}