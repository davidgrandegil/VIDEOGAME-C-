//////////////////////////////////////////////////////////////////////
// Autores: �lvaro Zornoza U�a 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// T�tulo: "Are you a good shooter?"
// Tutor: Miguel Hernando Guti�rrez
// Fecha: 2� Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Bonus.h"

Bonus::Bonus(float x,float y)
{
	posicion.Setx(x);
	posicion.Sety(y);
	lado=1.2f;
	giro=0;
}

Bonus::~Bonus()
{
}

void Bonus::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.Getx(),1,posicion.Gety());
	glRotatef(giro=giro+1.0,1,1,1);
	glColor3f(rand()/(float)RAND_MAX,rand()/(float)RAND_MAX,rand()/(float)RAND_MAX); 
    glutSolidCube(lado);
	glPopMatrix();
}



