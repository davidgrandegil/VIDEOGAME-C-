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
#include "Vector2D.h"
#include "glut.h"
#include <iostream>

class Bonus  
{
	Vector2D posicion;
	float lado;
	float giro;

public:
	Bonus(float,float);
	virtual ~Bonus();

	void Dibuja();

	friend class Interaccion;
};







