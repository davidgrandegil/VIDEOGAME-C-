//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(float xv,float yv)
{
	Setx(xv);
	Sety(yv);
}

Vector2D::~Vector2D(void)
{
}

void Vector2D::Setx(float x1)
{
	x=x1;
}

float Vector2D:: Getx()
{
	return  x;
}

void Vector2D:: Sety(float y1)
{
	y=y1;
}

float Vector2D::Gety()
{
	return y;
}

float Vector2D::Modulo()
{
	return (float)sqrt(abs(x*x+y*y));
}

float Vector2D::Argumento()
{
	return (float)atan2(y,x);
}	

Vector2D Vector2D::operator - (Vector2D &v)
{
	Vector2D res;
	res.x=x-v.x;
	res.y=y-v.y;
	return res;
}

Vector2D Vector2D::operator + (Vector2D &v)
{
	Vector2D res;
	res.x=x+v.x;
	res.y=y+v.y;
	return res;
}

float Vector2D::operator *(Vector2D &v)	
{
	return x*v.x+y*v.y;
}

Vector2D Vector2D::operator *(float f)
{
	Vector2D res;
	res.x=x*f;
	res.y=y*f;
	return res;
}

Vector2D Vector2D::Unitario()
{
	Vector2D retorno(x,y);
	float mod=Modulo();
	if(mod>0.00001)
	{
		retorno.x/=mod;
		retorno.y/=mod;
	}
	return retorno;
}
