/*
Programa C++ que Invierta las palabras en un archivo de texto.

la_serve.ccp

PARTICIPANTES:
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278
Donato Machado     -  1104816
Francisco Taveras  -  1107975

Fecha de realizacion:  19/03/2023
Fecha de presentacion: 23/03/2023
*/

#include <iostream>
#include<process.h>
#include<string>
#include<fstream>
#include <ctype.h>
#include <locale.h>

using namespace std;

string Lectura(string lector)// metodo para leer el archivo de texto
{
	ifstream archivo; //variable que funciona como lector del archivo

	archivo.open("leeme.txt", ios::in); //abrimos el archivo

	if (archivo.fail()) //condicional para validar que el archivo existe en la ruta
	{
		cout << "no se pudo abrir el archivo";
		exit(1);
	}

	while (!archivo.eof()) //bucle para obtener el texto del archivo
	{
		getline(archivo, lector);
	}

	archivo.close(); // cerramos el archivo

	return lector; // retornamos el texto obtenido
}

string Inverter(string palabra, int size) //metodo para invertir la palabra
{
	char aux;// auxiliares para guardar las palabras
	char aux2;

	for (int i = 0; i < size; i++) // en este bucle mientras el iterador sea menor que la longitud de la palabra este ira invirtiendo
		// mientras se reduce el rango del texto
	{
		aux = palabra[i];
		aux2 = palabra[size - 1];

		palabra[i] = aux2;
		palabra[size - 1] = aux;
		size--;
	}
	return palabra;
}

int main()
{
	setlocale(LC_ALL, ""); //para "validar" entrada de palabras en español
	string text;
	string inverter = "";
	int sizeText;

	text = Lectura(text) + " "; // obtenemos el texto del archivo

	cout << "Original: " << text << "\n\n";

	cout << "Volteao: ";

	for (int i = 0; text[i] != NULL; i++) // bucle que consigue palabra por palabra del texto
	{
		if (isalpha(text[i])) //isalpha determina si el caracter en esa posicion forma parte del alfabeto.
		{
			inverter += text[i];
		}
		else // cuando sea diferente quiere dicer que tenemos la palabra completa y se procede a invertir la misma
		{
			sizeText = inverter.length();
			inverter = Inverter(inverter, sizeText);
			cout << inverter << text[i];
			inverter = ""; //al final siempre reiniciamos a la variable que almacena la palabra
		}
	}

	cout << "\n\n";
	return 0;
}
