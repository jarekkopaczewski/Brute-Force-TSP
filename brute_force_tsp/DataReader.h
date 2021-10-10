#include <string>
#include "Graph.h"
#include <string>
using namespace std;

class DataReader
{
    public:
        DataReader();
        virtual ~DataReader();                         
        static Graph* readFile(std::string*);           //wczytuje plik -> parametr to rodzaj grafu
        static std::string* readFileNames();
        static std::string readName();      //wczytuje nazwe pliku
};
