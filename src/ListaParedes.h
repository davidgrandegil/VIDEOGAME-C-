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
#include "Pared.h"

#define MAX_PAREDES 100

class ListaParedes  
{
	Pared *ListaPared[MAX_PAREDES];
	int num;
public:
	ListaParedes();
	~ListaParedes();

	void Dibujar();
	bool Agregar(Pared *);
	
	int Getnum(){return num;}

	Pared * Buscar(int);
	
};

