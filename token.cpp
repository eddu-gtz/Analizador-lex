#include "token.h"
#include <iostream>
#include <iomanip>

using namespace std;

Token::Token()
{

}

Token::~Token()
{

}

Token::Token(int ID, string tok, int fila)
{
    id = ID;
    token = tok;
    row = fila;
}

string Token::getStatus()
{
    switch(id) {
        case 1://variable o palabra reservada
            return "variable";
        case 2://punto y coma
            return  "punto y coma";
        case 3://coma
            return "coma";
        case 4://parentesis apertura
            return  "parentesis izq";
        case 5://parentesis cierre
            return "parentesis der";
        case 6://llave apertura
            return  "llave izq";
        case 7://llave cierre
            return "llave der";
        case 8://igual
            return  "asignacion";
        case 9://numero entero
            return "entero";
        case 11://numero flotante
            return  "flotante";
        case 12:// mas o menos
            return "operador suma";
        case 14://operador logico
            return "operador logico";
        case 15://mult, div o mod
            return "operador aritmetico";
        case 16://fin
            return  "operador relacional";
        case 17:
            return "tipo de dato";
        case 18:
            return "palabra reservada"; //if
        case 19:
            return "palabra reservada"; //while
        case 20:
            return "palabra reservada"; //return
        case 21:
            return "palabra reservada"; //else
        case 22:
            return "fin ejecucion";
        default:
            return "error";
        }
}

void Token::imprimir(){
    cout<<setw(5);
    cout<<(char)186;
    cout<<setw(11)<<token;
    cout<<setw(36)<<getStatus();
    cout<<setw(8);
    cout<<(char)186;
    cout<<endl;

    /*cout<<"Token:  "<<token<<endl;
    cout<<"Tipo:   "<<getStatus()<<endl;
    cout<<"Fila:   "<<row<<endl;*/
}
