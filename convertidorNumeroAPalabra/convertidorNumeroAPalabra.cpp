/*
Realizar un programa C++ que simule convertir de numeros a palabras

PARTICIPANTES:
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278
Donato Machado�   �- �1104816
Francisco Taveras  -  1107975

Fecha de realizacion:  9/2/2023

*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdio.h>

using namespace std;

int validator;

//Arreglo que contiene los valores del 0 al 9 en letras
string unidades[]{ "","un", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
//Arreglo que contiene los valores de la tabla de 10 en letras
string tabladeldiez[]{ "diez", "once", "doce", "trece", "catorce", "quince","dieciseis", "diecisiete", "dieciocho", "diecinueve" };
//Arreglo que contiene que va de 10 en 10, a partir del vente en letras
string dediezendiez[]{ "", "", "vente", "trenta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };

int CinValidator(int n)
{
    while (cin.fail() || cin.peek() != '\n' || n < 0) //Condicion que establece que el numero introducido no puede contener ni caracteres ni letras.
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Funcion que ignora todo aquello que no sea un numero.
        cout << "Error: Solo se admiten valores numericos.\nIntroduzca el valor nuevamente y presione enter: ";
        cin >> n;
    }
    system("cls");
    return n;
}
string NombrarNumeros(long number)
{
    //Condicion que transcribir el numero introducido siempre y cuando sea menor que diez 
    if (number < 10)
    {
        return unidades[number];
    }
    //Condicion que transcribir el numero introducido siempre y cuando sea menor que vente 
    else if (number < 20)
    {
        return tabladeldiez[number - 10];
    }
    //Condicion que transcribir el numero introducido siempre y cuando sea menor que cien 
    else if (number < 100)
    {
        return dediezendiez[number / 10] + ((number % 10 != 0) ? " y " + NombrarNumeros(number % 10) : "");
    }
    //Condicion que transcribir el numero introducido siempre y cuando sea menor que mil 
    else if (number < 1000)
    {
        return NombrarNumeros(number / 100) + " cientos" + ((number % 100 != 0) ? " " + NombrarNumeros(number % 100) : "");
    }
    //Condicion que transcribir el numero introducido siempre y cuando sea menor que un millon 
    else if (number < 1000000)
    {
        return NombrarNumeros(number / 1000) + " mil" + ((number % 1000 != 0) ? " " + NombrarNumeros(number % 1000) : "");
    }
    //Condicion que transcribir el numero introducido siempre y cuando sea menor que un millardo 
    else if (number < 1000000000)
    {
        return NombrarNumeros(number / 1000000) + " millones" + ((number % 1000000 != 0) ? " " + NombrarNumeros(number % 1000000) : "");
    }
    return "error";
}

string NombrarDecimales(long number)
{
    if (number == 0)
    {
        return "cero";
    }
    else if (number < 10)  //Condicion que transcribir los centavos introducidos siempre y cuando sea menor que diez 
    {
        return unidades[number];
    }

    else if (number < 20) //Condicion que transcribir los centavos introducidos siempre y cuando sea menor que vente 
    {
        return tabladeldiez[number - 10];
    }
    else if (number < 100) //Condicion que transcribir los centavos introducidos siempre y cuando sea menor que cien
    {
        return dediezendiez[number / 10] + ((number % 10 != 0) ? " y " + NombrarNumeros(number % 10) : "");
    }

    return "error";
}

void menu() //Interfaz del programa
{

    system("cls");
    cout << "========  Convertir numero a palabra   =========\n\n";
    cout << "================================================\n";
    cout << "==              [1] Ingresar                  ==\n";
    cout << "==              [2] De que trata?             ==\n";
    cout << "==              [3] Salir                     ==\n";
    cout << "================================================\n";
    cout << "\nDigite su opcion y luego presione enter: ";
}

int main()
{
    bool sentinel = true;
    double entrada, salida;
    do
    {
        menu();
        cin >> validator;
        validator = CinValidator(validator);
        switch (validator) {
        case 1:
            system("cls");
            cout << "Introduzca el monto que desea transcribir y presione enter: ";

            cin >> entrada;
            salida = round((entrada - trunc(entrada)) * 100);
            entrada = CinValidator(entrada);

            cout << "\n" << "El monto introducido por completo fue: " << entrada << "." << salida << endl;

            cout << NombrarNumeros(entrada) + " pesos " + "con " + NombrarDecimales(salida) + " centavos \n" << endl;
            cout << "\nPresione cualquier tecla para continuar\n\n";
            system("PAUSE");
            break;
        case 2:
            system("cls");
            cout << "\nEl programa trata sobre convertir los numeros a letras, asi de sencillo. \nPresione cualquier tecla para continuar\n\n";
            system("PAUSE");
            break;
        case 3:
            system("cls");
            cout << "\nSaliendo...." << endl;//Mensaje de respuesta
            sentinel = false;//esperando interacion para salir
            break;
        default:
            system("cls");
            cout << "\nColoco una opcion no contemplada. Presione cualquier tecla para continuar\n\n";
            system("PAUSE");
            break;
        }
    } while (sentinel);

    return 0;
}