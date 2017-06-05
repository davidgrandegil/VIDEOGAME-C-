//////////////////////////////////////////////////////////////////////
// Autores: �lvaro Zornoza U�a 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// T�tulo: "Are you a good shooter?"
// Tutor: Miguel Hernando Guti�rrez
// Fecha: 2� Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#pragma once
#include "Disparo.h"

#define MAX_DISPAROS 200000

class ListaDisparos  
{
	Disparo *ListaDisp[MAX_DISPAROS];
	int num;

public:
	ListaDisparos();
	~ListaDisparos();

	void Dibujar();
	bool Agregar(Disparo *);
	void Mover(float);

	void EliminarDisp(int);
	void DestruirContenido();
	int Getnum(){return num;}

	Disparo * Buscar(int);
};

