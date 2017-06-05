//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Suelo.h"

Suelo::Suelo(float a,float b, float c,float d, unsigned char e, unsigned char f, unsigned char h)
{
	limite1.Setx(a);
	limite1.Sety(b);
	limite2.Setx(c);
	limite2.Sety(d);

	rojo=e;
	verde=f;
	azul=h;
}

Suelo::~Suelo(void)
{
}

void Suelo::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(rojo,verde,azul);

	glBegin(GL_POLYGON);
	
		glVertex3d(limite1.Getx(),0,limite1.Gety());
		glVertex3d(limite1.Getx(),0,limite2.Gety());
		glVertex3d(limite2.Getx(),0,limite2.Gety());
		glVertex3d(limite2.Getx(),0,limite1.Gety());
				
	glEnd();

	glEnable(GL_LIGHTING);
}




