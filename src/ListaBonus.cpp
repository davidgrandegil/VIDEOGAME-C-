//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "ListaBonus.h"

ListaBonus::ListaBonus()
{
	num=0;
	for (int x=0;x<100;x++)	ListaBon[x]=0; 
}

ListaBonus::~ListaBonus()
{
}

bool ListaBonus::Agregar(Bonus * p)
{
	if (num<100)
	{
		ListaBon[num++]=p;
		return true;
	}
	else return false;
}

void ListaBonus::Dibujar ()
{
	for (int i=0;i<num;i++)	ListaBon[i]->Dibuja();
}

void ListaBonus::EliminarBon(int a)
{
	if((a<0)||(a>=num))   return;

	else delete ListaBon[a];

	num-=1;
	for (int x=a;x<num;x++)	ListaBon[x]=ListaBon[x+1];
}

void ListaBonus::DestruirContenido()
{
	for(int i=0;i<num;i++)
		delete ListaBon[i];
	num=0;
}

Bonus * ListaBonus::Buscar(int a)
{
	if(a>=0)
	{
		if(num>a)  return ListaBon [a];
	}
	return 0;
}