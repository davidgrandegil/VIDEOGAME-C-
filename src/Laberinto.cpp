//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Laberinto.h"

Laberinto::Laberinto():s1(-40,-40,40,40,120,101,0)
{
	//Paredes exteriores
	lalista.Agregar(new Pared(40, 40,	40,   -40,	 20, 2,225));
	lalista.Agregar(new Pared(-40, -40, -40,    40,  20, 2,225));
	lalista.Agregar(new Pared(-40, -40,  40,   -40,  20, 200,225));
	lalista.Agregar(new Pared(-40,  40,  40,    40,  20, 200,225));

	//Paredes interiores
	lalista.Agregar(new Pared(  0, -30,  10,   -30,  120,120,90));
	lalista.Agregar(new Pared( 10, -30,  10,     0,	 120,120,90));
	lalista.Agregar(new Pared( 20, -20,  20,     0,  120,120,90));
	lalista.Agregar(new Pared( 30,   0,  30,    10,  120,120,90));
	lalista.Agregar(new Pared( 30,  10,  40,    10,  120,120,90));
	lalista.Agregar(new Pared( 20, -40,  20,   -30,  120,120,90));
	lalista.Agregar(new Pared( 20, -30,  30,   -30,  120,120,90));
	lalista.Agregar(new Pared( 30, -30,  30,   -10,  120,120,90));
	lalista.Agregar(new Pared( 30,  30,  30,    20,  120,120,90));
	lalista.Agregar(new Pared( 30,  20,  20,    20,  120,120,90));
	lalista.Agregar(new Pared( 20,  20,  20,    10,  120,120,90));
	lalista.Agregar(new Pared( 20,  10,  10,    10,  120,120,90));
	lalista.Agregar(new Pared( 10,  10,  10,     0,  120,120,90));
	lalista.Agregar(new Pared( 10, -10,   0,   -10,  120,120,90));
	lalista.Agregar(new Pared(  0, -20, -10,   -20,  120,120,90));
	lalista.Agregar(new Pared(-10, -20, -10,   -30,  120,120,90));
	lalista.Agregar(new Pared(-10, -30, -30,   -30,  120,120,90));
	lalista.Agregar(new Pared(-30, -20, -20,   -20,  120,120,90));
	lalista.Agregar(new Pared(-20, -20, -20,   -10,  120,120,90));
	lalista.Agregar(new Pared(-10, -10, -10,     0,  120,120,90));
	lalista.Agregar(new Pared(  0,  20,  10,    20,  120,120,90));
	lalista.Agregar(new Pared(  0,  30,  10,    30,  120,120,90));
	lalista.Agregar(new Pared( 10,  30,  20,    30,  120,120,90));
	lalista.Agregar(new Pared(-10,  40, -10,    20,  120,120,90));
	lalista.Agregar(new Pared(-10,  20, -30,    20,  120,120,90));
	lalista.Agregar(new Pared(-30,  20, -30,    10,  120,120,90));
	lalista.Agregar(new Pared(-20,  10, -10,    10,  120,120,90));
	lalista.Agregar(new Pared(-20,  10, -20,     0,  120,120,90));
	lalista.Agregar(new Pared(-20,  30, -30,    30,  120,120,90));
}

Laberinto::~Laberinto()
{
}

void Laberinto::Dibuja()
{
	s1.Dibuja();
	lalista.Dibujar();
}

ListaParedes& Laberinto::GetLista()
{
	return lalista;
}
