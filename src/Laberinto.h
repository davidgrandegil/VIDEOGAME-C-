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

