#ifndef CNODO_H_INCLUDED
#define CNODO_H_INCLUDED

#include "token.h"

class CNodo{
private:
    friend class CLista;

    CNodo* pSig = nullptr;
    CNodo* pAnt = nullptr;
    Token* dato;

    void insertarAdelante(Token*);
    Token* eliminarAdelante();
};

#endif // CNODO_H_INCLUDED
