#ifndef DATAMAP_H
#define DATAMAP_H

#include <iostream>
using namespace std;
class DataMap{
    private:
        string pais;
        string color;
    public:
        DataMap();
        void setColor(string pPais);
        string getColor(string pPais);    

};
#endif "DATAMAP_H"