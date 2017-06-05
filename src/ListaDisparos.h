//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
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

