#include "Field.h"
#include <iostream>
using namespace std;
Field::Field( string name, string value) : name(std::move(name)), value(std::move(value)) {}

const string Field::getName()
{
	return name;
}

void Field::setName(string name)
{
	Field::name = name;
}

const string Field::getValue()
{
	return value;
}

void Field::setValue(string value)
{
	Field::value = value;
}
void Field::print() {
    int i = 0;
    cout << name << " " << value << endl;
}

