#include <string>
#include <vector>
#include "Field.h"
#include "Function.h"
using namespace std;

class MyClass {
public:

    MyClass(string name, const vector<Function*> funcVector, const vector<Field*> fieldVector);
    MyClass(string name);

    virtual const vector <Function*> getFuncVector() const;
    virtual const vector <Field*> getFieldVector() const;

    virtual void setFuncVector(const vector<Function*> functionVector);
    virtual void setFieldVector(const vector<Field*> fieldVector);

    virtual const string& getName() const;

    void setName(string name);


    virtual void addFunc(string funcName, string value);
    virtual void addField(string fieldName, string value);
    virtual bool rmFunc(int id);
    virtual bool rmField(int id);
    
    virtual bool changeField(string newValue, int id);
    virtual bool changeFunc(string newValue, int id);

    bool operator==(const MyClass& rhs) const;

    bool operator!=(const MyClass& rhs) const;

    virtual ~MyClass();

    virtual void print();

    bool canExtend(MyClass* myClass);
    bool extend(MyClass* myClass);
    void deleteExtend();

protected:
    string name;
    vector<Field*> fieldVector;
    vector<Function*> funcVector;
    MyClass* parent;
};
