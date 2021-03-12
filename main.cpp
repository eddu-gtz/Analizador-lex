#include <iostream>
#include "analizador.h"
#include <iomanip>

using namespace std;

void printHeader();
void printFooter();

int main()
{
    string cadena;
    int opc;

    do{
        Analizador* lexico = new Analizador();

        system("cls");
        cin.sync();
        cout<< endl<< endl<< "Ingresa la cadena:  ";
        getline(cin, cadena);

        cout<<endl;
        printHeader();
        lexico->scan(cadena);
        printFooter();
        cout<<endl;

        cout << "Ingresa 1 para probar otra cadena, sino un 0: ";
        cin>>opc;

    }while(opc != 0);


    return 0;
}

void printHeader()
{
    char prev= ' ';

    cout<<endl;
    cout.width(5);
    cout<<(char)201; //Corner left-up

    cout.fill(205);
    cout.width(55);

    cout<<(char)187; //Corner right-up
    cout<<endl;

    cout.fill(prev); //Clean the fill

    cout.width(5);cout<<(char)186;
    cout.width(12);cout<<"Token";
    cout.width(8);cout<<(char)186;

    cout.width(19);cout<<"Tipo";
    cout.width(16);cout<<(char)186;


    cout<<endl;

    cout.width(5);
    cout<<(char)204; //T left

    for(int j=0; j < 54; j++)
        cout<<(char)205;

    cout<<(char)185; //T right
    cout<<endl;
}

void printFooter(){
    cout.width(5);
    cout<<(char)200; //Corner left-down

    for(int j=0; j < 54; j++)
        cout<<(char)205;

    cout<<(char)188; //Corner right-down
    cout<<endl;
}
