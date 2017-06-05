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

class Disparo  
{
	Vector2D posicion;
	Vector2D velocidad;
	float radio;
	int tipo;
public:
	Disparo(float, float, float, float, int);
	virtual ~Disparo();

	void Dibujar();
	void Mover(float);

	void SetPosicion(float x, float y);
	Vector2D GetPosicion();

	friend class Interaccion;
};
