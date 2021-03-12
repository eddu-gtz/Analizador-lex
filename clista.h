#ifndef CLISTA_H_INCLUDED
#define CLISTA_H_INCLUDED

#include "cnodo.h"
#include "token.h"

#define CLSID_LISTA 500

class CLista{
private:
    CNodo Inicio;
    CNodo Final;

public:

    CLista();
    ~CLista();

    void insertarAlInicio(Token*);
    void insertarAlFinal(Token*);

    Token* eliminarAlInicio();
    Token* eliminarAlFinal();

    int Size();
    bool isEmpty();
    bool isFull();

    void Imprimir();

    /*virtual void Salvar(fstream& );
    virtual void Cargar(fstream& );
    virtual int GetCLSID();*/

};


#endif // CLISTA_H_INCLUDED
