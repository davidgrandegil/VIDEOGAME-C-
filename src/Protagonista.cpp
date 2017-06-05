//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Protagonista.h"

Protagonista::Protagonista(float x, float y, float avan, float ang, float velang):Munieco(1.8,0.35,200,200,50)
{
	posicion.Setx(x);
	posicion.Sety(y);

	avance=avan;
	angulo=ang;
	velangulo=velang;
}

Protagonista::~Protagonista()
{
}

void Protagonista::TopeIzq()
{
	if(velangulo>0)
		velangulo=0;
	if(velangulo<-3.0)
		velangulo=-3.0;
}

void Protagonista::TopeDer()
{
	if(velangulo<0)
		velangulo=0;
	else if(velangulo>3.0)
		velangulo=2.0;
}

void Protagonista::TopeAdelante()
{
	if(avance<0)
		avance=0;
	if(avance>2)
		avance=3.5;
}

void Protagonista::TopeAtras()
{
	if(avance>0)
		avance=0;
	if(avance<-2)
		avance=-2;
}

Disparo* Protagonista::CrearDisp()
{
	Disparo* d=new Disparo (posicion.Getx(),posicion.Gety(),10*cos(angulo),10*sin(angulo),1);
	return d;
}

void Protagonista::Mover(float t)
{
	Munieco::Mover(t);
}
void Protagonista::DibujarPosicion()
{
	glColor3ub(0,0,255);
	glTranslatef(posicion.Getx(),2,posicion.Gety());
	glutWireSphere(1.5,200,200);
	glTranslatef(-posicion.Getx(),2,-posicion.Gety());
}
