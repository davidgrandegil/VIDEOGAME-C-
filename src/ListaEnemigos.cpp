//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "ListaEnemigos.h"

ListaEnemigos::ListaEnemigos()
{
	num=0;
	for (int x=0;x<MAX_ENEMIGOS;x++)  ListaEnem[x]=0;
}

ListaEnemigos::~ListaEnemigos()
{
}

bool ListaEnemigos::Agregar(Enemigo* p)
{
	for(int x=0;x<num;x++)
	{
		if(ListaEnem[x]==p)  
			false;
	}

	if (num<MAX_ENEMIGOS)
	{
		ListaEnem[num]=p;
		num+=1;
		return true;
	}
		else
			return false;
	return true;
}

void ListaEnemigos::Dibujar ()
{
	for (int i=0;i<num;i++)	ListaEnem[i]->Dibuja();
}

Enemigo * ListaEnemigos::Buscar(int a)
{
	if(num>a) return (static_cast<Enemigo*>(ListaEnem[a]));
	
	return (static_cast<Enemigo*>(ListaEnem[1]));
}

void ListaEnemigos::EliminarEnem(int a)
{
	if((a<0)||(a>=num))	return;
	else delete ListaEnem[a];

	num=num-1;
	for (int x=a;x<num;x++)	ListaEnem[x]=ListaEnem[x+1];
}

void ListaEnemigos::DestruirContenido()
{
	for(int i=0;i<num;i++)
		delete ListaEnem[i];
	num=0;
}
	
void ListaEnemigos::Mover(float t)
{
	for (int x=0;x<num;++x) ListaEnem[x]->Mover(t);
}

//void ListaEnemigos::DibujarPosiciones()
//{
//	for(int i=0;i<num;i++) 	ListaEnem[i]->DibujarPosicion();
//}