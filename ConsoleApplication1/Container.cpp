#include "Container.h"
#include <iostream>
using namespace std;

void Container::createNS(string name) {
    Namespace* ns = new Namespace(name);
    nsVector.emplace_back(*ns);
}

Namespace& Container::getNS(int id) {
    return nsVector[id];
}

bool Container::deleteNS(int id) {
    if (!hasId(id)) {
        return false;
    }
    else return true;
}

bool Container::hasId(int id) {
    return id < nsVector.size() && id >0;
}

void Container::print() {
    int i = 0;
    for (auto it = nsVector.begin(); it != nsVector.end(); ++it, ++i) {
        Namespace& curr = dynamic_cast<Namespace&>(*it);
        cout << i << ": ";
        curr.print();
    }
}

Container::Container() {}

Container::~Container() {
    nsVector.clear();
    nsVector.shrink_to_fit();
}
