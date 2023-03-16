#include "Function.h"
#include <iostream>
using namespace std;


Function::Function(string name, string value) : name(std::move(name)), value(std::move(value)) {}

void Function::setName(string name)
{
	Function::name = name;
}
const string Function::getName()
{
	return name;
}

const string Function::getValue()
{
	return value;
}

void Function::setValue(string value)
{
	Function::value = value;
}

void Function::print() {
	int i = 0;
	cout << name << " " << value << endl;
}

bool Function::operator==(const Function& rhs) const
{
	return name == rhs.name;
}

bool Function::operator!=(const Function& rhs) const
{
	return !(this->name == rhs.name);
}



