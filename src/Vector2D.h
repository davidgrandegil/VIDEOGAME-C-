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

class Vector2D  
{
	float x;
	float y;

public:
	Vector2D(float xv=0.0f,float yv=0.0f);
	~Vector2D();
	
	void Setx(float);
	float Getx();
	void Sety(float);
	float Gety();

	float Modulo();						//modulo del vector
	float Argumento();					//argumento del vector
	
	Vector2D Unitario();				//devuelve un vector unitario
	Vector2D operator - (Vector2D &);	//resta de vectores
	Vector2D operator + (Vector2D &);	//suma de vectores
	Vector2D operator *(float);			//producto por un escalar

	float operator *(Vector2D &);		//producto escalar
};
