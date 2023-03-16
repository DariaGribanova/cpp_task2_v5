#pragma once
#include <string>
using namespace std;
class Function
{
public:
    Function(string name, string value);

    virtual const string getName();

    void setName(string name);

    virtual const string getValue();

    void setValue(string);
    virtual void print();

    bool operator==(const Function& rhs) const;
    bool operator!=(const Function& rhs) const;
private:
    string name;
    string value;
};

