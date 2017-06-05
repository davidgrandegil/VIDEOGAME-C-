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

#include "ListaDisparos.h"
#include "ListaEnemigos.h"
#include "ListaBonus.h"
#include "Protagonista.h"
#include "Interaccion.h"
#include "Laberinto.h"
#include "ETSIDI.h"
#include <OpenGL.h>

class Mundo
{
	ListaDisparos losdisparos;
	ListaEnemigos losenemigos;
	ListaBonus losbonus;
	Protagonista prota;
	Laberinto ellaber;

	int vidas,puntos,bonus;
	double x_mira,y_mira,z_mira,x_ojo,y_ojo,z_ojo;

	enum Estado {INICIO=1,ELEGIR_NIVEL,JUGAR,PAUSA,PASO_DE_NIVEL,MUERTO} estado,estadoAnterior;
	enum SubEstado {NORMAL, PLANTA} subestado;
	enum Dificultad {FACIL=1,MEDIO,DIFICIL} dificultad;

public: 
	Mundo();
	virtual ~Mundo();

	void Mover(float);
	void Dibuja();
	void DibujaJuego();
	void DibujaPlanta();

	void TeclaDisparar(unsigned char, int x, int y);
	void TeclasMover(int, int x, int y);

	void accionesEntrada();
	void logicaEstados(unsigned char=0);

	void Sonido();
	void ImprimeInformacion();
	
	void Agregar();
};
