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
#include "Bonus.h"

class ListaBonus  
{	Bonus *ListaBon[10];
	int num;

public:
	ListaBonus();
	virtual ~ListaBonus();

	bool Agregar(Bonus *);
	void Dibujar();
	void EliminarBon(int);
	void DestruirContenido();
	int Getnum(){return num;}

	Bonus * Buscar(int);
};



