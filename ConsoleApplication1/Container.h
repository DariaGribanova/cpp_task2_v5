
#include "Namespace.h"
#include <vector>
#include <string>


    class Container
    {
        bool deleteNS(int id);

        bool hasId(int id);
    private:
        vector<Namespace> nsVector;
    public:
        Container();

        void print();

        virtual ~Container();

        void createNS (string name);

        Namespace& getNS(int id);
    };

