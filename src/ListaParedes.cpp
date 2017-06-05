//////////////////////////////////////////////////////////////////////
// Autores: �lvaro Zornoza U�a 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// T�tulo: "Are you a good shooter?"
// Tutor: Miguel Hernando Guti�rrez
// Fecha: 2� Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "ListaParedes.h"

ListaParedes::ListaParedes()
{
	num=0;
	for (int x=0;x<MAX_PAREDES;x++)  	ListaPared[x]=0;
}

ListaParedes::~ListaParedes()
{
}

bool ListaParedes::Agregar(Pared * p)
{
	if (num<MAX_PAREDES)
	{
		ListaPared[num++]=p;
		return true;
	}
	else return false;
}

void ListaParedes::Dibujar ()
{
	for (int i=0;i<num;i++)	ListaPared[i]->Dibuja();
}

Pared * ListaParedes::Buscar(int a)
{
	if(a>=0)
	{
		if(num>a) {return ListaPared [a];}
	}
	return 0;
}