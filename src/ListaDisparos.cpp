//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "ListaDisparos.h"

ListaDisparos::ListaDisparos()
{
	num=0;
	for (int x=0;x<MAX_DISPAROS;x++)	ListaDisp[x]=0;
}

ListaDisparos::~ListaDisparos(void)
{
}

bool ListaDisparos::Agregar(Disparo * p)
{
	for(int x=0;x<num;x++)
	{
		if(ListaDisp[x]==p)   return false;
	}

	if (num<MAX_DISPAROS)
	{
		ListaDisp[num++]=p;
		return true;
	}
	else return false;
	return true;
}

void ListaDisparos::Dibujar()
{
	for (int i=0;i<num;i++)	ListaDisp[i]->Dibujar();
}

void ListaDisparos::Mover(float t)
{
	for(int i=0;i<num;i++)	ListaDisp[i]->Mover(t);
}

void ListaDisparos::EliminarDisp(int a)
{
	if((a<0)||(a>=num))	return;
	else delete ListaDisp[a];

	num=num-1;
	for (int x=a;x<num;x++)	ListaDisp[x]=ListaDisp[x+1];
}

void ListaDisparos::DestruirContenido()
{
	for(int i=0;i<num;i++)
		delete ListaDisp[i];
	num=0;
}

Disparo * ListaDisparos::Buscar(int a)
{
	if(a>=0)
	{
		if(num>a)	{return ListaDisp [a];}
	}
	return 0;
}
