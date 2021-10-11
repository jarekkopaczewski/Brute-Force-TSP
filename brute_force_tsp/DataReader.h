#pragma once
#include <string>
#include "Graph.h"
#include <string>
using namespace std;

static class DataReader
{
    public:                        
        static Graph* readFile(std::string*);       
        static pair<string, int>* readFileNames();
        static std::string readName();
};
