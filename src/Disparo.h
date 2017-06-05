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
