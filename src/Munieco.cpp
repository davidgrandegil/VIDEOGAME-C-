//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Munieco.h"

Munieco::Munieco(float a,float b, unsigned char r, unsigned char v , unsigned char az)
{
	altura=a;
	radio=b;

	rojo=r;
	verde=v;
	azul=az;
}

Munieco::~Munieco()
{

}

void Munieco::Setangulo(float a)
{
	angulo=a;
}

void Munieco::Setavance(float a)
{
	avance=a;
}

void Munieco::Setvelangulo(float a)
{
	velangulo=a;
}

void Munieco::Mover(float t)
{
	angulo=angulo+velangulo*t;
	
	posicion.Setx(posicion.Getx()+avance*cos(angulo)*t);
	posicion.Sety(posicion.Gety()+avance*sin(angulo)*t);
}

void Munieco::Dibuja()
{

	glDisable(GL_LIGHTING);
			
	glColor3ub(rojo,verde,azul);
	
//piernas de delante
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.1,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.1,altura*0.40,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.3,altura*0.40,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.3,0,posicion.Gety()+radio*0.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.1,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.1,altura*0.40,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.3,altura*0.40,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.3,0,posicion.Gety()+radio*0.3);
	glEnd();

//piernas de atrás
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.1,0,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.1,altura*0.40,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.3,altura*0.40,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.3,0,posicion.Gety()-radio*0.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.1,0,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.1,altura*0.40,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.3,altura*0.40,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.3,0,posicion.Gety()-radio*0.3);
	glEnd();

//superficie de los pies
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.3,0,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.3,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.1,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.1,0,posicion.Gety()-radio*0.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.3,0,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.3,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.1,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.1,0,posicion.Gety()-radio*0.3);
	glEnd();

//clavicula
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.80,posicion.Gety()-radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.80,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.80,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.80,posicion.Gety()-radio*0.4);
	glEnd();
		
//piernas laterales
glColor3ub(rojo+20,verde+30,azul+30);

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.3,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.3,altura*0.40,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.3,altura*0.40,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.3,0,posicion.Gety()-radio*0.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.1,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.1,altura*0.40,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.1,altura*0.40,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.1,0,posicion.Gety()-radio*0.3);
	glEnd();

		
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.3,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.3,altura*0.40,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.3,altura*0.40,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.3,0,posicion.Gety()-radio*0.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.1,0,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.1,altura*0.40,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.1,altura*0.40,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.1,0,posicion.Gety()-radio*0.3);
	glEnd();

	
//cintura
	glColor3ub(rojo+10,verde+20,azul+10);
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.40,posicion.Gety()-radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.40,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.40,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.40,posicion.Gety()-radio*0.4);
	glEnd();

		
//pecho de delante
			
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.40,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.80,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.80,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.40,posicion.Gety()+radio*0.4);
	glEnd();

//pecho de atrás
	
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.40,posicion.Gety()-radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.80,posicion.Gety()-radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.80,posicion.Gety()-radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.40,posicion.Gety()-radio*0.4);
	glEnd();

//pecho lateral
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.40,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.80,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.80,posicion.Gety()-radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.40,posicion.Gety()-radio*0.4);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.40,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.80,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.80,posicion.Gety()-radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.40,posicion.Gety()-radio*0.4);
	glEnd();

//cara
	glColor3ub(rojo,verde,azul);
	glTranslatef(posicion.Getx(),altura*0.9,posicion.Gety());
	glutSolidSphere(altura*0.1,20,20);
	glTranslatef(-posicion.Getx(),-altura*0.9,-posicion.Gety());

//cinta
	glColor3ub(225,verde,0);
	glTranslatef(posicion.Getx(),altura*0.96,posicion.Gety());
	glRotatef(90,90,0,0);
	glutSolidTorus(altura*0.05,altura*0.1,20,20);
	glRotatef(90,-90,0,0);
	glTranslatef(-posicion.Getx(),-altura*0.96,-posicion.Gety());

	glColor3ub(225-10,verde-10,0);
	glTranslatef(posicion.Getx(),altura*0.96,posicion.Gety());
	glutSolidSphere(altura*0.11,20,20);
	glTranslatef(-posicion.Getx(),-altura*0.96,-posicion.Gety());

	glBegin(GL_POLYGON);

//brazo lateral
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.60,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.80,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.80,posicion.Gety()-radio*0.4);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.60,posicion.Gety()-radio*0.4);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.60,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.80,posicion.Gety()+radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.80,posicion.Gety()-radio*0.4);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.60,posicion.Gety()-radio*0.4);
	glEnd();

//brazo de delante y de atrás
	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.60,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.80,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.80,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.60,posicion.Gety()+radio*0.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.60,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.80,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.80,posicion.Gety()+radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.60,posicion.Gety()+radio*0.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.60,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.4,altura*0.80,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.80,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()+radio*0.6,altura*0.60,posicion.Gety()-radio*0.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.60,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.4,altura*0.80,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.80,posicion.Gety()-radio*0.3);
		glVertex3d(posicion.Getx()-radio*0.6,altura*0.60,posicion.Gety()-radio*0.3);
	glEnd();


//Indicador de disparo
	glLineWidth(3.0f);
		glBegin(GL_LINES);
			glVertex3f(posicion.Getx(),1.7,posicion.Gety());
			glVertex3f(posicion.Getx()+0.5*cos(angulo),1.75,posicion.Gety()+0.5*sin(angulo));
		glEnd();

	glEnable(GL_LIGHTING);

}
