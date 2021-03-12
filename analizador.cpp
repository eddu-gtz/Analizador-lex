#include "analizador.h"

#include <stdio.h>
#include <string.h>

#include "clista.h"

using namespace std;

Analizador::Analizador()
{

}

void Analizador::scan(std::string& entry)
{

    //Agregar un final a la cadena
    entry += ' ';

    int cont(0);
    int fila = 1;
    state = 0;
    aux="";
    //int tam = entry.size();

    //se lee el primer caracter de lo que ingreso el usuario
    char character = entry[cont++];

    //Mientras no sea el final de la candea hacer:
    while(character != '\0')
    {
        //Evaluar el estado
        switch(state)
            {
            ///ESTADO 0 entonces
            case 0:
            {
                //Si es una letra
                if(isalpha(character))
                {
                    state = 1; //Cambio de estado
                    aux += character; //se agrega el caracter a la variable aux
                }
                else if(character == ';')
                {
                    aux += character; //se agrega el caracter a la variable aux
                    addToken(2, fila); //se agrega el token con el estado 2
                }
                else if(character == ',')
                {
                    aux += character;
                    addToken(3, fila);
                }
                else if(character == '(')
                {
                    aux += character;
                    addToken(4, fila);
                }
                else if(character == ')')
                {
                    aux += character;
                    addToken(5, fila);
                }
                else if(character == '{')
                {
                    aux += character;
                    addToken(6, fila);
                }
                else if(character == '}')
                {
                    aux += character;
                    addToken(7, fila);

                }//si hay algun '=' '<' '>' '!' entonces:
                else if(character == '=' || character == '<' || character == '>' || character == '!')
                {
                    state = 16; //cambiar al estado 16
                    aux += character; //guardar el caracter
                }//Si es un DIGITO
                else if(isdigit(character))
                {
                    state = 9;//Cambiar al estado 9
                    aux += character;
                }//Si es un '.'
                else if(character == '.')
                {
                    state = 10;//cambiar al estado 10
                    aux += character;
                }//Si es un Signo '+' o '-'
                else if(character == '+' || character == '-')
                {
                    aux += character; //guardar caracter
                    addToken(12, fila);
                }//Si es un  '&' o '|'
                else if(character == '&' || character == '|')
                {
                    state = 14;//cambiar al estado 14
                    aux += character;
                }//OPERADORES ARITMETICOS * / %
                else if(character == '*' || character == '/' || character == '%')
                {
                    aux += character;
                    addToken(15, fila);
                }
                else if(!isspace(character))
                {
                    //en el caso de que no cumpla la condicion y no sea algun tipo de espacio
                    aux += character;
                    state = -1;//Estado de error
                }

            }
            break;
            ///Estado 1 PALABRAS RESERVADAS, VARIABLES
            case 1:
            {
                //Si es letra, '_' , o un digito
                if(isalpha(character) || character == '_' || isdigit(character))
                {
                    aux += character; //Guardar caracter
                }
                //Si no es digito ni '.'
                else if(!(isdigit(character) && character == '.'))
                {
                    //verificar si el token es un tipo de dato o una palabra reservada
                    if(isDataType(aux))
                    {
                        addToken(17, fila);
                    }
                    else
                    {
                        addToken(isReservedWord(aux), fila);
                    }
                    cont--;
                }
                else
                {
                    aux += character;
                    state = -1; //Estado de error
                }

            }
            break;
            /// ESTADO 9 - ENTEROS
            case 9:
            {
                if(isdigit(character))
                {
                    //el estado no cambia
                    aux += character;
                }//Si es un '.'
                else if(character == '.')
                {
                    aux += character; //Almacenar caracter
                    state = 10; //Cambio de estado
                }
                else if(isalpha(character))
                {
                    //llevarme a un caso de error
                    aux += character;
                    state = -1;
                }
                else if(isspace(character))
                {
                    //Ignorar el espacio
                    addToken(9, fila);
                }
                else
                {
                    addToken(9, fila);
                    cont--;
                    state = 0;
                }

            }
            break;
            ///ESTADO 10 - FLOTANTES
            case 10:
            {
                //si es digito
                if(isdigit(character))
                {
                    aux += character;
                    state = 11; //Cambio de estado
                }
                else if(isalpha(character))
                {
                    //llevarme a un caso de error
                    aux += character;
                    state = -1; //Estado de error
                }
                else if(isspace(character))
                {
                    aux += '0'; //agregar 0
                    addToken(11, fila);
                }
                else
                {
                    aux += '0';
                    cont--;
                    addToken(11, fila);
                }

            }
            break;
            ///CASE 11
            case 11:
            {
                if(isdigit(character))
                {
                    //el estado no cambia
                    aux += character;
                }
                else if(isalpha(character) || character == '.')
                {
                    //llevarme a un caso de error
                    aux += character;
                    state = -1;
                }
                else if(isspace(character))
                {
                    //si hay espacio, agregar token
                    addToken(11, fila);
                }
                else
                {
                    addToken(11, fila);
                    cont--;
                    state = 0;
                }


            }
            break;
            ///CASE 14 - OPERADOR LOGICO
            case 14:
            {
                //operador logico, and or
                if((character == '&'|| character == '|') && aux[0] == character)
                {
                    aux += character;
                    addToken(14, fila);
                }
                else if(character == '&' || character == '|')
                {
                    //llevarme a un caso de error
                    aux += character;
                    state = -1;
                    addToken(-1, fila);
                }
                else
                {
                    cont--;
                    addToken(-1, fila);
                }


            }
            break;
            ///ESTADO 16 - operador relacional -FIN
            case 16:
            {
                if(!( character == '=' )&& aux == "=")
                {
                    //analizar la asignacion
                    cont--;
                    addToken(8, fila);
                }
                else if(!(character == '='))
                {
                    cont--;
                    addToken(16, fila);
                }
                else if(character == '=')
                {
                    //solo <=, >=, !=, ==
                    aux += character;
                    addToken(16, fila);
                }


            }
            break;

            ///ESTADO DE ERROR
            case -1:
            {
                if(isdigit(character) || isalpha(character) || character == '.')
                {
                    aux += character;
                }
                else
                {
                    cont--;
                    addToken(-1, fila);
                }

            }
            break;
            }

        if(character == '\n')
        {
            fila++;
            //columna=1;
        }
        else
        {
            //columna++;
        }

        //Leer el siguiente caracter
        character = entry[cont++];
    }

    departure.Imprimir();

}

void Analizador::addToken(int ID, int fila )
{
    //Agregar Token a la lista
    Token* nToken = new Token( ID, aux, fila );

    departure.insertarAlFinal(nToken);
    aux="";
    state=0;

}

int Analizador::isDataType(std::string& str)
{
    if(str == "int" || str == "string" || str == "char" || str == "bool" || str == "double" || str == "float" || str == "void")
    {
        return true;
    }
    return false;
}

int Analizador::isReservedWord(std::string& str)
{
    if(str == "if" )
    {
        return 18;
    }
    else if(str == "while")
    {
        return 19;
    }
    else if (str == "return")
    {
        return 20;
    }
    else if (str == "else")
    {
        return 21;
    }

    //Variable
    return 1;
}
