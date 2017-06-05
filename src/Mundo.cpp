//////////////////////////////////////////////////////////////////
 //Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
 //Asignatura: Informatica Industrial
 //Trabajo: Juego Libre con OpenGL (glut)
 //Título: "Are you a good shooter?"
 //Tutor: Miguel Hernando Gutiérrez
 //Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////

#include "Mundo.h"

Mundo::Mundo():prota(-35,5,0,0,0)
{
	estado=INICIO;
	subestado=NORMAL;
	puntos=0;
	bonus=0;
}

Mundo::~Mundo()
{
}

void Mundo::Agregar()
{
	bonus=0;
	losdisparos.DestruirContenido();
	losenemigos.DestruirContenido();
	losbonus.DestruirContenido();

	if(dificultad==FACIL)
	{
		vidas=4;
		losenemigos.Agregar(new Enemigo(-25,-25,1,0,0));
		losenemigos.Agregar(new Enemigo(15,15,1,0,0));
		losenemigos.Agregar(new Enemigo(25,25,1,0,0));
		losenemigos.Agregar(new Enemigo(-5,-5,1,0,0));
	}
	if(dificultad==MEDIO)
	{
		vidas=2;
		losenemigos.Agregar(new Enemigo(-25,-25,1,0,0));
		losenemigos.Agregar(new Enemigo(15,15,1,0,0));
		losenemigos.Agregar(new Enemigo(25,25,1,0,0));
		losenemigos.Agregar(new Enemigo(-5,-5,1,0,0));
		losenemigos.Agregar(new Enemigo(-15,-15,1,0,0));
		losenemigos.Agregar(new Enemigo(-20,25,1,0,0));
		losenemigos.Agregar(new Enemigo(35,-30,1,0,0));
		losenemigos.Agregar(new Enemigo(-35,0,1,0,0));
	}
	if(dificultad==DIFICIL)
	{
		vidas=1;
		losenemigos.Agregar(new Enemigo(-25,-25,1,0,0));
		losenemigos.Agregar(new Enemigo(15,15,1,0,0));
		losenemigos.Agregar(new Enemigo(25,25,1,0,0));
		losenemigos.Agregar(new Enemigo(-5,-5,1,0,0));
		losenemigos.Agregar(new Enemigo(-15,-15,1,0,0));
		losenemigos.Agregar(new Enemigo(-20,25,1,0,0));
		losenemigos.Agregar(new Enemigo(35,-30,1,0,0));
		losenemigos.Agregar(new Enemigo(-35,0,1,0,0));
		losenemigos.Agregar(new Enemigo(25,-25,1,0,0));
		losenemigos.Agregar(new Enemigo(5,-5,1,0,0));
		losenemigos.Agregar(new Enemigo(-15,15,1,0,0));
		losenemigos.Agregar(new Enemigo(-20,-25,1,0,0));
		losenemigos.Agregar(new Enemigo(35,30,1,0,0));
		losenemigos.Agregar(new Enemigo(-35,10,1,0,0));
	}
	losbonus.Agregar(new Bonus(35,-33));
	losbonus.Agregar(new Bonus(-25,16));
	losbonus.Agregar(new Bonus(-25,25));
	losbonus.Agregar(new Bonus(-5,-25));
	losbonus.Agregar(new Bonus(18,13));
	}

void Mundo::Dibuja()
{
	if(subestado==NORMAL)DibujaJuego();
	if(subestado==PLANTA)DibujaPlanta();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	//

	gluLookAt(x_ojo,y_ojo,z_ojo,  // posicion del ojo
		x_mira,y_mira,z_mira,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, .0);

	losdisparos.Dibujar();
	losenemigos.Dibujar();
	prota.Dibuja();
	losbonus.Dibujar();
	ellaber.Dibuja();

	if(subestado==PLANTA)    // Esto dibuja las posiciones de los muñecos en la visión en PLANTA
	{
		prota.DibujarPosicion();
		//losenemigos.DibujarPosiciones();
	}
	ImprimeInformacion();

	//Al final, cambiar el buffer
	glutSwapBuffers();
}

void Mundo::DibujaJuego()
{
	x_ojo=((prota.Getpos()).Getx()+prota.Getradio()*cos(prota.Getangulo()));
	y_ojo=prota.Getaltura();
	z_ojo=((prota.Getpos()).Gety()+prota.Getradio()*sin(prota.Getangulo()));
	x_mira=((prota.Getpos()).Getx()+cos(prota.Getangulo()));
	y_mira=prota.Getaltura();
	z_mira=((prota.Getpos()).Gety()+sin(prota.Getangulo()));
}

void Mundo::DibujaPlanta()
{
	x_ojo=0;
	y_ojo=140.0;
	z_ojo=0.5;
	x_mira=0;
	y_mira=0;
	z_mira=0;
}

void Mundo::Mover(float t)
{
	accionesEntrada();
	logicaEstados();

	if(estado!=JUGAR)return;
	if(subestado==PLANTA)return;
		
	losenemigos.Mover(t);
	losdisparos.Mover(t);
	prota.Mover(t);

	//interaccion protagonista(jugador)-paredes
		for(int x=0;x<(ellaber.GetLista()).Getnum();x++)
			Interaccion::ChoqueProtaPared(prota,*((ellaber.GetLista()).Buscar(x)));
		
	//interaccion protagonista(jugador)-disparos
		for(int x=0;x<losdisparos.Getnum();x++)
		{
			if(Interaccion::ChoqueDisparoProta(*losdisparos.Buscar(x),prota))
				{ 
					ETSIDI::play("sonidos/risa.mp3");
					vidas=vidas-1;
				}
		}

	//interaccion enemigos-disparos
		for(int x=0;x<losdisparos.Getnum();x++)
		{
			for(int y=0;y<losenemigos.Getnum();y++)
			{
				if(Interaccion::ChoqueDisparoEnemigo(*losdisparos.Buscar(x),*losenemigos.Buscar(y)))
				{
					if(y<losenemigos.Getnum())
					{
						losenemigos.EliminarEnem(y);
						ETSIDI::play("sonidos/Bala.mp3");
					}

					if(x<losdisparos.Getnum())
						losdisparos.EliminarDisp(x);
					puntos=puntos+50;
				}
			}
		}
	//interaccion enemigos-paredes
		for(int x=0;x<(ellaber.GetLista()).Getnum();x++)
			for(int y=0;y<losenemigos.Getnum();y++)
				Interaccion::ChoqueEnemigoPared(*losenemigos.Buscar(y),*(ellaber.GetLista()).Buscar(x));
			
	//interaccion pared-disparos
		for(int x=0;x<losdisparos.Getnum();x++)
		{
			for(int y=0;y<(ellaber.GetLista()).Getnum();y++)
			{
				if(x<losdisparos.Getnum())
				{
					if(Interaccion::ChoqueDisparoPared(*losdisparos.Buscar(x),*(ellaber.GetLista()).Buscar(y)))
						losdisparos.EliminarDisp(x);
				}
			}
		}

	//interaccion protagonista-bonus
		for(int x=0;x<losbonus.Getnum();x++)
		{
			if(x<losbonus.Getnum())
			{
				if(Interaccion::ChoqueProtaBonus(prota,*(losbonus.Buscar(x))))
				{
					losbonus.EliminarBon(x);
					ETSIDI::play("sonidos/Bong.mp3");
					puntos=puntos+60;
					bonus++;
				}
			}
		}

	//disparos enemigos
		for(int x=0;x<losenemigos.Getnum();x++)
		{
			if(rand()%20==0)
			{
				Disparo* p=losenemigos.Buscar(x)->CrearDisp();
				losdisparos.Agregar(p);
			}
		}
}

void Mundo::TeclaDisparar(unsigned char key, int x, int y)
{
	if(key==' ') 
	{
		//para el jugador
		
		Disparo* d=prota.CrearDisp();
		losdisparos.Agregar(d);
	}
	logicaEstados(key);
}

void Mundo::TeclasMover(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT ://rotacion hacia izquierda
		prota.Setvelangulo(prota.Getvelangulo()-0.1);
		prota.TopeIzq();
			break;			
	case GLUT_KEY_RIGHT://rotacion hacia derecha
		prota.Setvelangulo(prota.Getvelangulo()+0.1);
		prota.TopeDer();
		break;
	case GLUT_KEY_UP://avance
		prota.Setavance(prota.Getavance()+0.1);
		prota.TopeAdelante();
		break;
	case GLUT_KEY_DOWN://retroceso
		prota.Setavance(prota.Getavance()-0.1);
		prota.TopeAtras();
		break;
	}
}

void Mundo::accionesEntrada()
{
	bool igual=false;
	int estadoAnt=estadoAnterior;
	if(estadoAnterior==estado)igual=true;
	estadoAnterior=estado;

	if(igual)return;
	//acabamos de entrar en un estado: acciones de entrada
	switch(estado)
	{
	case INICIO:
		Sonido();
		break;
	case ELEGIR_NIVEL:
		break;
	case JUGAR:
		Sonido();
		subestado=NORMAL;
		puntos=0;
		break;
	case PASO_DE_NIVEL:
		Sonido();
		break;
	case MUERTO:
		Sonido();
		break;
	case PAUSA:
		Sonido();
		break;
	}
}

void Mundo::logicaEstados(unsigned char tecla)
{
	switch(estado)
	{
	case INICIO:
		if(tecla=='e')
			estado=ELEGIR_NIVEL;
		if(tecla=='s')exit(0);
		break;

	case ELEGIR_NIVEL:
		if(tecla=='1')
		{ 
			dificultad=FACIL;
			Agregar();
			estado=JUGAR;
		}
		if(tecla=='2') 
		{
			dificultad=MEDIO;
			Agregar();
			estado=JUGAR;
		}
		if(tecla=='3') 
		{   
			dificultad=DIFICIL;
			Agregar();
			estado=JUGAR;
		}
		break;
		
	case JUGAR:
		if(losenemigos.Getnum()==0)estado=PASO_DE_NIVEL;
		if(vidas==0)estado=MUERTO;
		if(tecla=='p')
		{
			ETSIDI::play("sonidos/pausaBeep.mp3");
			estado=PAUSA;
		}
		if((subestado==PLANTA)&&(tecla)) 
		{
			subestado=NORMAL;
			Sonido();
		}
		else if((bonus>0)&&(subestado==NORMAL)&&(tecla=='4'))
		{
			subestado=PLANTA;
			bonus--;
			Sonido();
		}
		break;

	case PAUSA:
		if(tecla=='p')  
			estado=JUGAR; 
		if(tecla=='s')
			exit(0);
		break;

	case PASO_DE_NIVEL:
  		if(tecla=='s')exit(0);
		if(tecla=='e')
		{
			if(dificultad==FACIL)
			{
				dificultad=MEDIO;
				Agregar();
				estado=JUGAR;
				break;
			}
			if(dificultad==MEDIO)
			{
				dificultad=DIFICIL;
				Agregar();
				estado=JUGAR;
				break;
			}
		}
		break;

	case MUERTO:
		if(tecla=='s')exit(0);
		if(tecla=='e')
		{
			Agregar();
			estado=JUGAR;
		}
		break;
	}
}

void Mundo::Sonido()
{	
	if (estado==INICIO)
			ETSIDI::playMusica("sonidos/Prelude.mp3",true);
	if(estado==JUGAR)
	{
		if(subestado==NORMAL)
			ETSIDI::playMusica("sonidos/PPlatina.mp3",true);
		if(subestado==PLANTA)
			ETSIDI::playMusica("sonidos/war.mp3",true);
	}
	if(estado==PAUSA)
			ETSIDI::playMusica("sonidos/Prelude.mp3",true);
	if(estado==PASO_DE_NIVEL)
		ETSIDI::playMusica("sonidos/WelcomingCeremony.mp3",true);
	if(estado==MUERTO)
		ETSIDI::playMusica("sonidos/InterruptedFireworks.mp3",true);
}

void Mundo::ImprimeInformacion()
{
	char ayuda[200]="";
	int ver=400, hor=80;
	switch(estado)
	{ 
	case INICIO:
		OpenGL::Print("Are you a good shooter?",hor,ver,255,255,255);   //Este es el mensaje de introduccion
		OpenGL::Print("David Grande y Alvaro Zornoza",hor,ver+20,255,255,255);
		OpenGL::Print("Tutor: Miguel Hernando",hor,ver+40,255,255,255);
		OpenGL::Print("Universidad Politecnica de Madrid",hor,ver+60,255,255,255);
		OpenGL::Print("Copyright  2016. Alvaro Zornoza y David Grande ",hor,ver+80,255,255,255);
		OpenGL::Print("Utiliza las flechas del teclado para MOVER y la barra espaciodora para DISPARAR. Pulsa (4) para UTILIZAR el bonus",hor,ver+120,0,0,0);

		sprintf_s(ayuda,"Pulse E (empezar) S (salir)");
		break;

	case ELEGIR_NIVEL:
		sprintf_s(ayuda,"Elige un nivel. Facil(1), Medio(2) o Dificil(3)");
		break;

	case JUGAR:
		sprintf_s(ayuda,"Vidas: %d, Puntos: %d, Enemigos:%d, Bonus:%d",vidas,puntos,losenemigos.Getnum(),bonus);
		break;

	case PAUSA:
		sprintf_s(ayuda,"PAUSA. Pulsa P para continuar o S para salir");
		break;

	case PASO_DE_NIVEL:
		if(dificultad!=DIFICIL)
			sprintf_s(ayuda,"HAS GANADO. Pulse E (Siguiente NIVEL) S (salir)");
		else
			sprintf_s(ayuda,"HAS GANADO EL NIVEL DIFICIL. S (salir)");
		break;	

	case MUERTO:
		sprintf_s(ayuda,"GAME OVER. Pulse E (empezar) S (salir)");
		break;		
	}
	OpenGL::Print(ayuda,80,30,255,255,0);
}


