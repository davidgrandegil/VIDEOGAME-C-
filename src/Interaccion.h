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

#include "Disparo.h"
#include "Pared.h"
#include "Bonus.h"
#include "Enemigo.h"
#include "Protagonista.h"

class Interaccion
{
public:
	Interaccion(void);
	virtual ~Interaccion(void);

	//Interacción con la pared
	static bool ChoqueProtaPared (Protagonista&,Pared&);
	static bool ChoqueEnemigoPared (Enemigo&,Pared&); 
	static bool ChoqueDisparoPared (Disparo&,Pared&); //Destrucción del disparo al impactar con la pared

	//Interacción con los disparos
	static bool ChoqueDisparoEnemigo (Disparo&,Enemigo&); 
	static bool	ChoqueDisparoProta (Disparo&,Protagonista&);

	//Interaccion con el bonus
	static bool ChoqueProtaBonus (Protagonista&,Bonus&);
	
	
};



