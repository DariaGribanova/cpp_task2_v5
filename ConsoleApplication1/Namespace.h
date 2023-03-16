
#include <string>
#include <utility>
#include <vector>
#include "MyClass.h"
using namespace std;
class Namespace
{
public:
    Namespace(string name, const vector <MyClass*>& classVector);

    explicit Namespace(string name);

    ~Namespace();

    bool operator==(const Namespace& rhs) const;

    bool operator!=(const Namespace& rhs) const;


    MyClass* rmCLass(int id);
    
    void addClass(MyClass* myClass);
    MyClass*& get(int id);

    void print();

private:
    string name;
    vector<MyClass*> classVector;
};

