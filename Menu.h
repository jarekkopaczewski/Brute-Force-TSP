#include <string>
#include "Graph.h"

class Menu
{   
    public:
        Menu();
        virtual ~Menu();
        void start();

    private:
        int mode;
        int opcja;
        int strct;
        std::string** logs;
        Graph* graph;
        int* menuMax;
        bool menu();
        void showText();
        int readKey();
        void mainMenu(int);
        void bruteMenu(int);
};
