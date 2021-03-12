#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include "states.h"
#include <string>

class Token {

private:
    friend class Analizador;

    //States estados[25];
    int id;
    std::string estado;
    std::string token;
    int row;

public:

    //Constructor y destructor
    Token();
    ~Token();
    //constructor parametrizado
    Token(int ,std::string , int );

    std::string getStatus();
    void imprimir();
};

#endif // TOKEN_H_INCLUDED
