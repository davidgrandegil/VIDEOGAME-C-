//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Pared.h"
#include "glut.h"
#include "OpenGL.h"

Pared::Pared(float a=0,float b=0,float c=0,float d=0,unsigned char r=0,unsigned char v=0,unsigned char az=0)
{
	limite1=Vector2D(a,b);
	limite2=Vector2D(c,d);
	rojo=r;
	verde=v;
	azul=az;
}

Pared::~Pared()
{
}

void Pared::Dibuja()
{
	glEnable(GL_LIGHTING);
	unsigned int textura=OpenGL::CargaTextura("imagenes/Pared.bmp"); 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textura);

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glTexCoord2d(0.0,0.0);	
		glVertex3d(limite1.Getx(),10,limite1.Gety());
		glTexCoord2d(0.0,3);
		glVertex3d(limite2.Getx(),10,limite2.Gety());
		glTexCoord2d(3,3);
		glVertex3d(limite2.Getx(),0,limite2.Gety());
		glTexCoord2d(3,0.0);
		glVertex3d(limite1.Getx(),0,limite1.Gety());
	glEnd();

	glEnable(GL_LIGHTING);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

float Pared::Distancia(Vector2D punto, Vector2D *direccion)
{
	Vector2D u=(punto-limite1);
	Vector2D v=(limite2-limite1).Unitario();
	float longitud=(limite1-limite2).Modulo();

	Vector2D dir;
	float valor=u*v;
	float distancia=0;

	if(valor<0)
		dir=u;
	else if(valor>longitud)
		dir=(punto-limite2);
	else
		dir=u-v*valor;

	distancia=dir.Modulo();
	if(direccion!=0) 
		*direccion=dir.Unitario();
	
	return distancia;
}


