#include "HashTable.h"

HashTable::HashTable(int pLargo){
    this->largo= pLargo;
    this->tabla = new list<string>[pLargo];
}

void HashTable::insertar(string pCoordenada, string pId, string pColor){
    if(this->tabla[0].empty()){
        tabla[0].push_back(pId);
        tabla[0].push_back(pColor);
        tabla[0].push_back(pCoordenada);
    }
    else{
        for(int i = 1; i< this->largo; i++){
            if(this->tabla[i].empty()){
                tabla[i].push_back(pId);
                tabla[i].push_back(pColor);
                tabla[i].push_back(pCoordenada);
                break;
            }
        }
    }
}

void HashTable::printHash(){
    for(int i=0; i<this->largo;i++){
        if(tabla[i].empty()){
            break;
        }
        for(auto x : tabla[i]){
            cout<<x<<"-->";
        }
        cout<<endl;
    }
}

string HashTable::getColor(string pID){
    for(int i =0; i<this->largo;i++){
        if(tabla[i].front()== pID){
            int cont =0;
            for(auto x: tabla[i]){
                if(cont==1){
                    return x;
                }
                cont++;    
            }
        }
    }
}

string HashTable::getID(string pAdds){
    for(int i = 0; i<this->largo;i++){
        if(tabla[i].back()==pAdds){
            return tabla[i].front();
        }
    }
}

list<string> HashTable::obtenerCoordenadas(){
    list<string> coordenadas[largo];

    for(int i=0; i<largo;i++){
        string coordenadaActual = tabla[i].back();
        coordenadas[i].push_back(coordenadaActual);
    }
    return *coordenadas;
}