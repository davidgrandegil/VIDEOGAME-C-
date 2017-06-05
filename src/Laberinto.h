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
#include "Suelo.h"
#include "ListaParedes.h"

class Laberinto  
{
	Suelo s1;
	ListaParedes lalista;

public:
	Laberinto();
	virtual ~Laberinto();

	void Dibuja();

	ListaParedes& GetLista();
};

