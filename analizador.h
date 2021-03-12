#ifndef ANALIZADOR_H_INCLUDED
#define ANALIZADOR_H_INCLUDED

#include "token.h"
#include "clista.h"

#include <string>

class Analizador{

private:


    int state; //Estado
    std::string aux;

    //Objeto Lista de tipo Token
    CLista departure;


public:

    Analizador();
    void scan(std::string& );

    void addToken(int ,int  );

    int isDataType(std::string& );

    //Token isReservedWord(std::string&);

    int isReservedWord(std::string& );

};

#endif // ANALIZADOR_H_INCLUDED
