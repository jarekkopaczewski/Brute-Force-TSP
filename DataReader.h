#include <string>
#include "Graph.h"

class DataReader
{
    public:
        DataReader();
        virtual ~DataReader();                         
        static Graph* readFile(int);        //wczytuje plik -> parametr to rodzaj grafu
        static std::string readName();      //wczytuje nazwe pliku
};
