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
#include "Enemigo.h"
#define MAX_ENEMIGOS 14

class ListaEnemigos 
{
	Enemigo *ListaEnem[MAX_ENEMIGOS];
	int num;

public:
	ListaEnemigos();
	~ListaEnemigos();

	void Dibujar();

	bool Agregar(Enemigo *);
	void Mover(float);
	void EliminarEnem(int);
	void DestruirContenido();
	//void DibujarPosiciones();

	int Getnum (){return num;}

	Enemigo * Buscar(int);
	
};
