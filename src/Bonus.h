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







