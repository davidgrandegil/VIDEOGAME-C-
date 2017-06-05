//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Interaccion.h"

Interaccion::Interaccion(void)
{
}	

Interaccion::~Interaccion(void)
{
}

bool Interaccion::ChoqueEnemigoPared(Enemigo& hombre,Pared& pared)
{	
	Vector2D dir;

	float distan=pared.Distancia(hombre.posicion,&dir);
	distan-=hombre.radio;

	if(distan<0.0f)
	{	
		hombre.posicion=hombre.posicion-dir*distan+dir*1.5;
		hombre.avance=0.0f;
		hombre.velangulo=3.0f;
		return true;
	}
	return false;
}

bool Interaccion::ChoqueDisparoPared(Disparo& disparo,Pared& pared)
{
	float distan=pared.Distancia(disparo.posicion);
	distan-=disparo.radio;
	if(distan<0.3f)
		return true;
	return false;
}


bool Interaccion::ChoqueDisparoEnemigo(Disparo &disparo,Enemigo &ene)
{
  	if(disparo.tipo==1)
	{
			Vector2D prueba;
			prueba=ene.Getpos()-disparo.GetPosicion();
			float distan=prueba.Modulo();
			if( distan<(disparo.radio+ene.radio))
				return true;
	}
	return false;

}
bool Interaccion::ChoqueDisparoProta(Disparo &disparo,Protagonista &p)
{	
	if(disparo.tipo==2)
	{
		Vector2D prueba;
		prueba=p.Getpos()-disparo.GetPosicion();
		float distan=prueba.Modulo();
		if( distan<disparo.radio+p.radio)
			return true;
	}	
	return false;
}

bool Interaccion::ChoqueProtaBonus(Protagonista& prota,Bonus& bonus)
{
	float distan=(prota.posicion-bonus.posicion).Modulo();
	if(distan<bonus.lado+prota.radio)
		return true;	
	return false;
}

bool Interaccion::ChoqueProtaPared(Protagonista& hombre,Pared& pared)
{	
	Vector2D dir;

	float distan=pared.Distancia(hombre.posicion,&dir);
	distan-=hombre.radio;

	if(distan<0.0f)
	{	
		hombre.posicion=hombre.posicion-dir*distan+dir*1.5;
		hombre.avance=0.0f;
		hombre.velangulo=0.0f;
		return true;
	}
	return false;
}
