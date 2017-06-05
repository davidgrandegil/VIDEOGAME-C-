//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////


//clase derivada de la clase base Munieco
#pragma once

#include <iostream>
#include "Munieco.h"
#include "Disparo.h"

class Enemigo : public Munieco 
{

public:
	Enemigo(float,float,float,float,float);
	virtual ~Enemigo();

	Disparo* CrearDisp();

	void Mover (float);
	//void DibujarPosicion();

	friend class Interaccion;
};

