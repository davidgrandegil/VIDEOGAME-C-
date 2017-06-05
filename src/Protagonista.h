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

#include "Munieco.h"
#include "Disparo.h"
#include "glut.h"

class Protagonista  : public Munieco
{
public:
	Protagonista(float,float,float,float,float);
	virtual ~Protagonista();

	void TopeAdelante();
	void TopeAtras();
	void TopeIzq();
	void TopeDer();

	Disparo* CrearDisp();
	void Mover(float);
	void DibujarPosicion();

	friend class Interaccion;
	
};

