#include "clista.h"

CLista::CLista()
{
    //Enlazar los nodos cabecera
    Inicio.pSig = &Final;
    Final.pAnt = &Inicio;
}

CLista::~CLista()
{
    //Eliminar todos los nodos de la lista
    while(Inicio.pSig != &Final){
        Inicio.eliminarAdelante();
    }
}

void CLista::insertarAlInicio(Token* ndato)
{

    Inicio.insertarAdelante(ndato);

}

void CLista::insertarAlFinal(Token* ndato)
{
    //Regresar uno para poder insertar al final
    Final.pAnt->insertarAdelante(ndato);

}

Token* CLista::eliminarAlInicio()
{

    return Inicio.eliminarAdelante();

}

Token* CLista::eliminarAlFinal()
{
    //Regresar dos posiciones para poder eliminar al final
    return Final.pAnt->pAnt->eliminarAdelante();

}

int CLista::Size()
{
    //Contar el numero de nodos que contiene la lista
    int numNodos(0);

    CNodo* aux = Inicio.pSig;

    while( aux != &Final){
        numNodos++;
        aux = aux->pSig;
    }

    return numNodos;
}

bool CLista::isEmpty()
{
    ///Si regresa verdadero es porque esta vacia
    return Inicio.pSig == &Final;
}

bool CLista::isFull()
{
    CNodo* pNodo = new (CNodo);
    ///Si regresa nullptr es porque se acabo la memoria
    return pNodo == nullptr;
}

void CLista::Imprimir()
{

    CNodo *pActual = new CNodo();
    pActual = Inicio.pSig;

    while( pActual != &Final ){
        pActual->dato->imprimir();

        pActual = pActual->pSig;
    }

}

/*
void CLista::Salvar(fstream& out)
{
    CIterador it;

    out<<GetCLSID()<<endl;
    out<<Size()<<endl;
    for(it = Begin(); it != End(); it++){
        it.pActual->dato->Salvar(out);
    }

}

void CLista::Cargar(fstream& in)
{
    int tamanio(0);
    int CLSID(0);

    in>>tamanio;

    for(int i=0; i<tamanio; i++){

        in>>CLSID;
        Token* pObj = 0;

        switch(CLSID){
            case CLSID_PERSONA:
                pObj = new CPersona();
                break;

            case CLSID_ALUMNO:
                pObj = new CAlumno();
                break;

            case CLSID_PROFESOR:
                pObj = new CProfesor();
                break;

            case CLSID_AUTO:
                pObj = new CAuto();
                break;

            case CLSID_PATRULLA:
                pObj = new CPatrulla();
                break;

            case CLSID_TAXI:
                pObj = new CTaxi();
                break;

            case CLSID_BLINDADO:
                pObj = new CBlindado();
                break;

            case CLSID_AUTOPARTE:
                pObj = new CAutoparte();
                break;

            case CLSID_MOTOR:
                pObj = new CMotor();
                break;

            case CLSID_LLANTA:
                pObj = new CLlanta();
                break;

            default:
                pObj = 0;

        }

        if(pObj == 0){
            cout<<" Hubo un error al cargar los datos"<<endl;
            system("pause");
            break;
        }
        else{
            pObj->Cargar(in);
            insertarAlFinal(pObj);
        }
    }
}

int CLista::GetCLSID()
{
    return CLSID_LISTA;
}
*/
