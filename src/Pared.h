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

class Pared
{
	Vector2D limite1;
	Vector2D limite2;
	unsigned char rojo,verde,azul;

public:
	Pared(float,float,float,float,unsigned char,unsigned char,unsigned char);
	virtual ~Pared();

	float Distancia(Vector2D, Vector2D *direccion=0);
	void Dibuja();

	friend class Interaccion;

};

