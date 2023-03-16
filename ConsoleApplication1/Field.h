
#include <string>
using namespace std;
class Field
{
public:
    Field(string name, string value);

    virtual const string getName();

    void setName(string name);

    virtual const string getValue() ;

    void setValue(string value);
    virtual void print();

private:
    string name;
    string value;
};

