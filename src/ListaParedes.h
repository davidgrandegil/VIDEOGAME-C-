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

