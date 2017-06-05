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
#include "glut.h"
#include "Vector2D.h"
#include <math.h>

class Munieco  //clase base
{
protected:
	Vector2D posicion;

	float avance;
	float angulo;
	float velangulo;

	float altura;
	float radio;

	unsigned char rojo,verde,azul;

public:
	Munieco(float,float, unsigned char, unsigned char, unsigned char);
	virtual ~Munieco();

	void Setangulo(float);
	void Setavance(float);
	void Setvelangulo(float);

	float Getangulo()	{return angulo;}
	float Getavance()	{return avance;}
	float Getvelangulo(){return velangulo;}

	float Getaltura()	{return altura;}
	float Getradio()	{return radio;}

	Vector2D Getpos() {return posicion;}

	void Dibuja();

	virtual void Mover(float);
		
};
