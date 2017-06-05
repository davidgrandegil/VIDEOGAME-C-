//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Disparo.h"
#include <stdlib.h>

Disparo::Disparo(float x,float y,float vx,float vy,int z)
{
	posicion.Setx(x);
	posicion.Sety(y);
	velocidad.Setx(vx);
	velocidad.Sety(vy);

	tipo=z;
	if(tipo==1)radio=0.15; //Disparo del protagonista
	if(tipo==2)radio=0.3;  //Disparo del enemigo
}

Disparo::~Disparo()
{
}

void Disparo::Dibujar()
{
	if(tipo==1) 
	{
		glTranslatef(posicion.Getx(),1.0,posicion.Gety());
		glColor3f(0,0,30);
		glutSolidSphere(radio,20,20);
		glTranslatef(-posicion.Getx(),-1.0,-posicion.Gety());
	}
	if(tipo==2) 
	{
		glTranslatef(posicion.Getx(),1.0,posicion.Gety());
		glColor3f(100,0,0);
		glutSolidSphere(radio,20,20);
		glTranslatef(-posicion.Getx(),-1.0,-posicion.Gety());
	}
}

void Disparo::Mover(float t)
{
	posicion=posicion+velocidad*t;
}

void Disparo::SetPosicion(float x, float y)
{
	posicion.Setx(x);
	posicion.Sety(y);
}

Vector2D Disparo::GetPosicion()
{
	return posicion;
}
