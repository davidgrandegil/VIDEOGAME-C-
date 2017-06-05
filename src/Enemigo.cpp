//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Enemigo.h"

Enemigo::Enemigo(float x, float y, float avan, float ang, float velang):Munieco(((rand()%15+20)/10),((rand()%4+10)/10),(rand()%100+155),200,(rand()%120+125))
{
	posicion.Setx(x);
	posicion.Sety(y);

	avance=avan;
	angulo=ang;
	velangulo=velang;
}

Enemigo::~Enemigo(void)
{
}

Disparo* Enemigo::CrearDisp()
{
	Disparo* d=new Disparo (posicion.Getx()+radio+cos(angulo),posicion.Gety()+radio+sin(angulo),17*cos(angulo),17*sin(angulo),2);
	return d;
}

void Enemigo::Mover(float t)
{
	if((avance==0)&&(rand()%50==0))
	{
		avance=2.5;
		velangulo=0;
	}

	Munieco::Mover(t);
}
//void Enemigo::DibujarPosicion()
//{
//	glColor3ub(0,0,255);
//	glTranslatef(posicion.Getx(),1,posicion.Gety());
//	glutWireSphere(2.5,200,200);
//	glTranslatef(-posicion.Getx(),1,-posicion.Gety());
//}
