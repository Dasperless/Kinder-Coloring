#ifndef HashTable_H
#define Hastable_H

#include <iostream>
#include <list>
#include <cstring>
#include <array>
using namespace std;

class HashTable{
    private:
        int largo;
        list<string> *tabla;
    
    public:
        HashTable(int pLargo);
        void insertar(string pCoordenada,string pId,string pColor);
        void eliminar(string pID);
        void printHash();
        string getID(string pCoordenada);
        string getColor(string pID); 
        list<string> obtenerCoordenadas();

};
#endif 