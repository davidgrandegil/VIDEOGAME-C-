//////////////////////////////////////////////////////////////////////
// Autores: �lvaro Zornoza U�a 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// T�tulo: "Are you a good shooter?"
// Tutor: Miguel Hernando Guti�rrez
// Fecha: 2� Cuatrimestre  Curso 2015/2016
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

